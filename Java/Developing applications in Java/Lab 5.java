package com.company;
import java.util.*; // импорт всех классов из пакета java.util
// Создаем класс "Работники школы"
class School_Employees
{
    private int office_num;
    private String FIO;
    private String prof;
    private String sex;
    //Создаем конструктор и выставляем начальные значения переменных
    School_Employees()
    {
        this.office_num = 0;
        this.FIO = "NULL";
        this.prof = "NULL";
        this.sex = "NULL";

    }
    School_Employees(int office_num, String FIO, String prof, String sex)
    {
        this.office_num = office_num;
        this.FIO = FIO;
        this.prof = prof;
        this.sex = sex;
    }
    //Переопределяем метод
    @Override
    public String toString()
    {
        return office_num + " | " + FIO + " | " + prof + " | " + sex;
    }
}
// Создаем класс "Классы"
class Classes  //Расширяем исходный класс
{
    private String num_class;
    private int official_num;
    private String spec_class;
    private int class_room;
    public String NumClass() {
        return num_class;
    }
    Classes()
    {
        this.num_class = "NULL";
        this.official_num = 0;
        this.spec_class = "NULL";
        this.class_room = 0;
    }
    Classes(String num_class)
    {
        this.num_class = num_class;
        this.official_num = 0;
        this.spec_class = "NULL";
        this.class_room = 0;
    }
    Classes(String num_class, int official_num, String spec_class, int class_room)
    {

        this.num_class = num_class;
        this.official_num = official_num;
        this.spec_class = spec_class;
        this.class_room = class_room;
    }
    @Override
    public String toString()
    {
        return num_class + " | " + official_num + " | " + spec_class + " | " + class_room;
    }
}
// Создаем класс "Ученики"
class Pupils extends TreeSet<com.company.Pupils> implements Comparable<com.company.Pupils> //Используем интерфейс Comparable для сравнения и сортировки
{
    private String num_class;
    private int num_magazine;
    private String FIO;
    private String SEX;
    public int GetNumMagazine()
    {
        return this.num_magazine;
    }

    public String GetNumclass()
    {
        return this.num_class;
    }

    Pupils()
    {
        this.num_class = "NULL";
        this.num_magazine = 0;
        this.FIO = "NULL";
        this.SEX = "NULL";
    }

    Pupils(String num_class, int num_magazine, String FIO, String SEX)
    {
        this.num_class = num_class;
        this.num_magazine = num_magazine;
        this.FIO = FIO;
        this.SEX = SEX;
    }

    Pupils(String num_class, int num_magazine)
    {
        this.num_class=num_class;
        this.num_magazine=num_magazine;
    }
    @Override
    public int compareTo(com.company.Pupils arg1)
    {
        com.company.Pupils entry = (com.company.Pupils) arg1;
        int result = num_class.compareTo(entry.num_class);
        if(result != 0)
        {
            return result;
        }
        result = num_magazine - entry.num_magazine;
        if(result != 0)
        {
            return (int) result / Math.abs(result);
        }
        return 0;
    }

    @Override
    public String toString()
    {
        return num_class + " | " + num_magazine + " | " + FIO + " | " + SEX;
    }

}

public class Main
{

    public static void main(String[] args)
    {
        //Добавляем записи в массивы
        com.company.School_Employees e[] = {
                new com.company.School_Employees(100,"Петров Станислав Васильевич", "Учитель","М"),
                new com.company.School_Employees(101,"Петрова Валентина Григореьвна", "Учитель","Ж"),
                new com.company.School_Employees(102,"Рыбакова Анна Ивановна", "Завуч","Ж"),
                new com.company.School_Employees(103,"Федоров Юрий Васильевич", "Директор","М"),
                new com.company.School_Employees(104,"Смирнов Антон Юрьевич", "Учитель","М")
        };
        com.company.Classes c[] = {
                new com.company.Classes("10А",101,"Иностранные языки (английский и немецкий)",203),
                new com.company.Classes("11Б",100,"Математика и физика",212)
        };
        com.company.Pupils p[] = {
                new com.company.Pupils("10А",1,"Иванов Сергей Петрович", "М"),
                new com.company.Pupils("10А",2,"Костин Петр Васильевич", "М"),
                new com.company.Pupils("10А",3,"Матросова Елена Ивановна", "Ж"),
                new com.company.Pupils("11Б",1,"Богданов Юрий Сергеевич", "М"),
                new com.company.Pupils("11Б",2,"Потапова Юлия Петровна", "Ж"),
                new com.company.Pupils("11Б",3,"Сорокина Ольга Петровна", "Ж"),
                new com.company.Pupils("11Б",4,"Сидоров Андрей Петрович", "М")
        };
        //Реализация интерфейса java.util.Map
        Map<Integer, com.company.School_Employees> se1 = new HashMap<Integer, com.company.School_Employees>(); // Используем класс HashMap и создаем хеш-карту
        for(int i=0; i<e.length; i++)
        {
            se1.put(i,e[i]); //Помещаем данные на карту
        }
        System.out.println("\n«Работники школы»");
        for (Map.Entry<Integer, com.company.School_Employees> item: se1.entrySet()) //Перебираем все записи на карте
        {
            System.out.println("Ключ: " + item.getKey() + " : Значение: " + item.getValue()); //Вывод данных в виде пар "ключ-значение"
        }
        com.company.School_Employees changeSet = new com.company.School_Employees(105,"Петров Станислав Васильевич", "Учитель","М");
        System.out.println("Произведем обновление записи с ключом 0: ");
        se1.replace(0, changeSet);
        for (Map.Entry<Integer, com.company.School_Employees> item: se1.entrySet())
        {
            System.out.println("Ключ: " + item.getKey() + " : Значение: " + item.getValue());
        }
        System.out.println("Удаляем все записи из словаря ");
        Iterator<Map.Entry<Integer, com.company.School_Employees>> se1Map = se1.entrySet().iterator();
        while (se1Map.hasNext())
        {
            se1Map.next();
            se1Map.remove();
        }
        if (se1.isEmpty())
        {
            System.out.println("Словарь пуст!");
        }
        //Реализация интерфейса java.util.List
        List<com.company.Classes> Class = new ArrayList<>(); //Используем класс ArrayList и создаем список для хранения объектов
        for (int i = 0; i < c.length; i++)
        {

            Class.add(i,c[i]); //Добавляем в список элементы массива
        }
        System.out.println("«Классы»");
        for (com.company.Classes item: Class)
        {
            System.out.println(item);
        }
        com.company.Classes setClass = new com.company.Classes("11Б",105,"Математика и физика",215);
        System.out.println("Меняем элемент: " + Class.get(1));
        System.out.println("Обновляем");
        Class.set(1,setClass);
        System.out.println("Измененный элемент: " + Class.get(1));
        System.out.println("Удаляем элементы из списка");

        while (!Class.isEmpty())
        {
            Class.remove(0);
        }

        if (Class.isEmpty()) System.out.println("Список пустой!");
        //Реализация интерфейса java.util.SortedSet
        System.out.println("\n«Ученики»");
        SortedSet<com.company.Pupils> Pupil = new TreeSet<com.company.Pupils>(); //Используем интерфейс SortedSet и класс TreeSet. Создаем отсортированный набор.
        for (int i = 0; i < p.length; i++)
        {
            Pupil.add(p[i]); //Добавляем элементы массива в набор
        }
        for (com.company.Pupils item: Pupil)
        {
            System.out.println(item); //Вывод значений
        }
        com.company.Pupils setPupils = new com.company.Pupils("10А",1,"Шульман Екатерина Михайловна", "Ж");
        if (Pupil.contains(p[0]) && Pupil.contains(setPupils))
        {
            System.out.println("Меняем элемент: " + p[0]);
            Pupil.remove(p[0]);
            Pupil.add(setPupils);
        }
        else
        {
            System.out.println("Элемент не найден!");
        }
        System.out.println("Удаляем элементы из множества");
        Iterator<com.company.Pupils> itPupil = Pupil.iterator();
        while (itPupil.hasNext())
        {
            itPupil.next();
            itPupil.remove();
        }
        if (Pupil.isEmpty())
        {
            System.out.println("Множество пустое!");
        }
    }
}