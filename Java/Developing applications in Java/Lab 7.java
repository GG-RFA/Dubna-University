package com.company;
import java.util.SortedMap; // Подключаем пакет для использования интерфейса SortedMap
import java.util.TreeMap; // Подключаем пакет для использования интерфейса TreeMap

class SeaBattle // Реализуем класс "Морской бой"
{
    private String NameShip; // Объявляем переменную "Название корабля"
    private int size; // Объявляем переменную "Размер корабля"
    private boolean state[]; // Объявляем переменную "Cостояние корабля"

    SeaBattle() // Создаем конструктор
    {
        // Задаем начальные значения
        this.NameShip = null;
        this.size = 0;
        this.state = null;
    }

    SeaBattle(String Ship, int size) // Создаем ссылки на объекты
    {
        this.NameShip = Ship;
        this.size = size;
        this.state = new boolean[size];
        for (int i = 0; i < size; i++)
        {
            this.state[i] = true;
        }
    }

    @Override //Переопределяем метод
    public String toString()
    {
        int count = 0;
        String str = "Название корабля: " + NameShip + "\n" + "Размер корабля: " + size + "\n" + "Состояние корабля: ";
        for (int i = 0; i < size; i++)
        {
            if (state[i] == true)
            {
                count++;
            }
        }
        str += String.valueOf(count) + "/" + String.valueOf(size) + "\n"; // Складываем параметры, заданные в переменной str, и состояние корабля
        return str; // Выводим параметры корабля
    }
}

class Chess // Создаем класс "Шахматы"
{
    private String FigureName; // Объявляем переменную "Название фигуры"
    private String FigureColor; // Объявляем переменную "Цвет фигуры"

    public String GetFigureName() // Функция, возвращающая значение FigureName
    {
        return FigureName;
    }
    public String GetFigureColor() // Функция, возвращающая значение FigureColor
    {
        return FigureColor;
    }

    Chess() // Создаем конструктор
    {
        // Задаем начальные значения
        this.FigureName = null;
        this.FigureColor = null;
    }

    Chess(String nameFigures, String colorFigures) // Создаем ссылки на объекты
    {
        this.FigureName = nameFigures;
        this.FigureColor = colorFigures;
    }

    @Override //Переопределяем метод
    public String toString()
    {
        return "Название фигуры: " + FigureName + "\n" + "Цвет фигуры: " + FigureColor + "\n"; // Выводим параметры шахматной фигуры
    }
}

class PlayField<T> // Создаем обобщенный класс "Игровое поле"
{
    private SortedMap<String, T> ptr;
    private int VerticalSize; // Задаем переменную "Размер по вертикали"
    private int HorizontalSize; // Задаем переменную "Размер по горизонтали"

    public int GetVerticalSize() // Функция, возвращающая значение VerticalSize
    {
        return VerticalSize;
    }
    public int GetHorizontalSize() // Функция, возвращающая значение HorizontalSize
    {
        return HorizontalSize;
    }

    PlayField() // Создаем конструктор
    {
        // Задаем начальные значения
        ptr = null;
        VerticalSize = 0;
        HorizontalSize = 0;
    }

    PlayField(int VerticalSize, int HorizontalSize) // Создаем ссылки на объекты
    {
        this.VerticalSize = VerticalSize;
        this.HorizontalSize = HorizontalSize;
        ptr = new TreeMap<>();
        char KeyField = 'E'; // Создаем переменную "Ключ", по которой будет осуществляться поиск элемента
        for (int i = 0; i < VerticalSize; i++, KeyField++)
        {
            for (int j = 0; j < HorizontalSize; j++)
            {
                ptr.put(String.valueOf(KeyField) + String.valueOf(j + 1), null); // Задаем вид ключа
            }
        }
    }

    public void Add(T item) 
    {
        if (VerticalSize * HorizontalSize < ptr.size()) // Проверка на заполнение
        {
            System.out.println("Поле уже заполнено!");
            return;
        }
        for (SortedMap.Entry<String, T> arg : this.ptr.entrySet())
        {
            if (arg.getValue() == null)
            {
                ptr.put(arg.getKey(), item);
                return;
            }
        }
    }

    public T GetIndex(int PosI, int PosJ) // Создаем функцию для поиска объекта по индексу
    {
        try
        {
            int count = 0;
            if (PosI > VerticalSize || PosJ > HorizontalSize) // Проверка на размерность индекса
            {
                throw new Exception("Индексы не могут быть больше размера поля!"); // Выброс исключения
            }
            for (SortedMap.Entry<String, T> item : ptr.entrySet())
            {
                if (count == (PosI * 10 + PosJ) && item.getValue() != null)
                {
                    return item.getValue();
                }
                count++;
            }
            throw new Exception("Объект с заданным индексом не найден!"); // Выброс исключения
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage()); // Вывод сообщения
        }
        return null; // Возвращаем пустое значение
    }
    public T GetKey(String key) // Создаем функцию для поиска объекта по ключу
    {
        try
        {
            if (ptr.get(key) == null) // Проверка ключа на пустоту
            {
                throw new Exception("Объект с заданным ключом не найден!"); // Выброс исключения
            }
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage()); // Вывод сообщения
        }
        return ptr.get(key); // Вывод объекта по ключу
    }
}

public class Main // Создаем класс Main
{
    public static void main(String[] args)
    {
        Chess figures[] = {
                // Добавляем записи в массив
                new Chess("Пешка", "Белый"),
                new Chess("Ладья", "Белый"),
                new Chess("Конь", "Белый"),
                new Chess("Слон", "Белый"),
                new Chess("Ферзь", "Белый"),
                new Chess("Король", "Белый"),
                new Chess("Пешка", "Черный"),
                new Chess("Ладья", "Черный"),
                new Chess("Конь", "Черный"),
                new Chess("Слон", "Черный"),
                new Chess("Ферзь", "Черный"),
                new Chess("Король", "Черный"),
        };
        PlayField<Chess> tableChess = new PlayField<>(8,8); // Задаем размерность игрового поля "Шахматы"
        tableChess.Add(figures[0]); // Задаем фигуру "Белая Пешка"
        tableChess.Add(figures[1]); // Задаем фигуру "Белая Ладья"
        tableChess.Add(figures[2]); // Задаем фигуру "Белый Конь"
        System.out.println(tableChess.GetIndex(0, 0)); // Вывод фигуры по индексам
        System.out.println(tableChess.GetIndex(9, 9)); // Вывод фигуры по индексам, превышающим размер поля
        System.out.println(tableChess.GetKey("E3")); // Вывод фигуры по ключу
        SeaBattle ships[] = {
                // Добавляем записи в массив
                new SeaBattle("Лодка", 1),
                new SeaBattle("Эсминец", 2),
                new SeaBattle("Крейсер", 3),
                new SeaBattle("Линкор", 4),
        };
        PlayField<SeaBattle> tableSeaBattle = new PlayField<>(10, 10); // Задаем размерность игрового поля "Морской бой"
        tableSeaBattle.Add(ships[0]); // Задаем корабль "Лодка"
        tableSeaBattle.Add(ships[1]); // Задаем корабль "Эсминец"
        tableSeaBattle.Add(ships[2]); // Задаем корабль "Крейсер"
        System.out.println(tableSeaBattle.GetIndex(0, 0)); // Вывод корабля по индексам
        System.out.println(tableSeaBattle.GetIndex(11, 11)); // Вывод корабля по индексам, превышающим размер поля
        System.out.println(tableSeaBattle.GetKey("E2")); // Вывод корабля по ключу
    }
}