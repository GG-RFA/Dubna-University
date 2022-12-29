package com.company;
import java.util.*; // Импорт всех классов из пакета java.util
import java.util.concurrent.Semaphore; //Подключаем пакет для использования семафор

// Cоздаём класс "Газеты"
class Newspapers
{
    private String PaperNum; // Объявляем переменную "Номер газеты"
    private String PaperName; // Объявляем переменную "Название газеты"
    private String price; // Объявляем переменную "Цена"
    private Semaphore sem; // Объявляем семафору, ограничивающую число газет

    public String getPaperNum() // Функция, возвращающая значение PaperNum
    {
        return PaperNum;
    }

    public String getPaperName() // Функция, возвращающая значение PaperName
    {
        return  PaperName;
    }

    public String getPrice() // Функция, возвращающая значение price
    {
        return price;
    }

    Newspapers() // Создаем конструктор
    {
        // Задаем начальные значения
        this.PaperNum = null;
        this.PaperName = null;
    }

    Newspapers(String PaperNum, String PaperName, String price) // Создаем ссылки на объекты
    {
        this.PaperNum = PaperNum;
        this.PaperName = PaperName;
        this.price = price;
    }

    @Override //Переопределяем метод
    public String toString()
    {
        return PaperNum + " | " + PaperName + " | " + price + ""; // Выводим информацию о газете
    }
}

// Создаем обобщенный класс "Киоск"
class Kiosk<T> extends Thread
{
    private Semaphore sem; // Объявляем семафору
    private ArrayList<T> StockPapers; // Объявляем переменную склада газет
    private boolean OpenClose; // Объявляем переменную "Открыт/Закрыт"

    public boolean getOpenClose() // Функция, возвращающая значение "Открыт/Закрыт"
    {
        return OpenClose;
    }

    public Semaphore getSem() // Функция, возвращающая значение семафоры
    {
        return sem;
    }

    public ArrayList<T> getStockPapers() // Функция, возвращающая значение склада газет
    {
        return StockPapers;
    }

    Kiosk()
    {
        StockPapers = new ArrayList<T>(); // Создаем список для хранения объектов
        OpenClose = true; // Задаем значение переменной "Открыт/Закрыт" по умолчанию - "Открыт"
    }
    public void addNewspaper(T item) // Функция для добавления записи
    {
        StockPapers.add(item);
    }

    @Override // Переопределяем метод
    public void run()
    {
        sem = new Semaphore(1, true); // Объявляем семафору
        while (OpenClose)
        {
            if (StockPapers.size() == 0) //Проверка на наличие газет. Если газеты на складе отсутствуют, то киоск закрывается
            {
                OpenClose = false; // Меняем значение "Открыт/Закрыт"
            }
            this.interrupt(); // Прерываем поток
        }
    }
}

// Создаем обобщенный класс "Покупатель"
class Buyer<T> extends Thread
{
    private int IdBuyer; // Объявляем номер покупателя
    private boolean queue; // Объявляем очередь
    private Semaphore sem; // Объявляем семафору для ограничения числа покупателей
    private T data; // Объявляем переменную data, выводящую информацию о газете
    private Kiosk newspaper;

    public int getIdBuyer() // Функция, возвращающая номер покупателя
    {
        return IdBuyer;
    }

    Buyer(int IdBuyer, Kiosk newspaper, T data) // Создаем ссылки на объекты
    {
        this.IdBuyer = IdBuyer;
        this.newspaper = newspaper;
        this.sem = newspaper.getSem();
        this.data = data;
        queue = false; // Устанавливаем значение очереди по умолчанию
    }

    @Override // Переопределяем метод
    public void run()
    {
        try
        {
            CheckQeque(); // Вызов функции CheckQeque
            sem.acquire(1); // В случае если есть очередь, запрашиваем разрешение на выполнение
            BuyNewspaper(); // Вызов функции BuyNewspaper
            sem.release(); // Освобождаем разрешение
        }
        catch (InterruptedException e) // Выброс исключения
        {

        }
    }

    public void CheckQeque() // Создаем функцию для проверки на наличие очереди
    {
        if (queue)
        {
            return;
        }
        System.out.println("Покупатель под номером " + IdBuyer + " встал в очередь!");
        queue = true;
    }

    void BuyNewspaper() // Создаем функцию для покупки газеты
    {
        if (!newspaper.getOpenClose())
        {
            return;
        }
        int time = new Random().nextInt(100); // Генерируем случайный временной промежуток для каждого покупателя
        try {
            sleep(time);
            if (newspaper.getStockPapers().contains(data)) // Проверка на наличие газеты на складе
            {
                System.out.println("Покупатель под номером " + IdBuyer + " купил газету! (" + data +"). Покупатель простоял в очереди "+ time +" секунд."); // Вывод информации в случае, если покупатель приобрел газету
                newspaper.getStockPapers().remove(data); // Информация о газете удаляется со склада
            }
            else
            {
                System.out.println("Покупатель под номером " + IdBuyer + " не смог купить газету (" + data + "), т.к. её не было в наличии! Покупатель простоял в очереди "+ time +" секунд."); // Вывод информации в случае, если покупатель не приобрел газету
            }
        }
        catch (InterruptedException e) // Выброс исключения
        {

        }
        queue = false;
    }

}

public class Main // Создаем класс Main
{
    public static void main(String[] args)
    {
        System.out.println("Продажа газет в киоске");
        final int PaperSize = 8; // Задаем размер массива
        Newspapers newspapers[] = {
                // Добавляем записи в массив
                new Newspapers("№ 225-2021", "Коммерсантъ", "60 рублей"),
                new Newspapers("№ 279-2021", "Российская газета - неделя", "48 рублей"),
                new Newspapers("№ 08(95)", "THE ART NEWSPAPER RUSSIA", "100 рублей"),
                new Newspapers("№ 45-2021", "Парламенсткая газета", "15 рублей"),
                new Newspapers("№ 49-2021", "Аргументы и факты", "20 рублей"),
                new Newspapers("№ 190-2021", "Ежедневная деловая газета РБК", "23 рубля"),
                new Newspapers("№ 233-2021", "Известия", "25 рублей"),
                new Newspapers("№ 49-2021", "Телек PRESSA.RU", "10 рублей")
        };
        Kiosk<Newspapers> newspaper = new Kiosk<>();
        for (int i = 0; i < 8; i++) // Устанавливаем кол-во доступных для покупки газет
        {
            int random = (int)(Math.random() * PaperSize);
            newspaper.addNewspaper(newspapers[random]); // Добавляем записи из массива в случайном порядке
        }
        try
        {
            newspaper.start(); // Запускаем поток
            int i = 1;
            while(newspaper.getOpenClose()) // Пока киоск открыт, выполняем условие
            {
                Buyer b = new Buyer(i, newspaper, newspapers[(int)(Math.random() * PaperSize)]);
                b.start(); // Запускаем поток покупателей
                i++;
                Thread.sleep(100); // Приостанавливаем поток на 100 миллисекунд
                b.interrupt(); // Прерываем поток покупателей
            }
            newspaper.interrupt(); // Прерываем поток
        }
        catch (Exception e) // Выброс исключения
        {

        }
    }
}