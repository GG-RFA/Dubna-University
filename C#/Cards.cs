using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Collections.Generic;


namespace Lab_8
{
    class Cards //Класс колоды
    {
        //Создание колоды карт
        private Card[] Deck = new Card[37];

        public Cards()
        {
            for (int i = 1; i <= 4; i++) //цикл для масти
            {
                for (int j = 6; j <= 14; j++)  //цикл для карт(6,7,8,9,10,валет и т.д.)
                {
                    Deck[(i - 1) * 9 + (j - 5)] = new Card(i, j); //формирование колоды
                }
            }
        }

        public void Sort() //ф-ия сортировки колоды
        {
            int x0, x1, x2, x3, y0, y1, y2, y3;
            int i = 1;
            for (; i < 36;) //"прогоняем" колоду
            {
                x0 = Deck[i].Suit;
                x1 = Deck[i].Num;
                i++;
                x2 = Deck[i].Suit;
                x3 = Deck[i].Num;
                i++;
                y0 = Deck[i].Suit;
                y1 = Deck[i].Num;
                i++;
                y2 = Deck[i].Suit;
                y3 = Deck[i].Num;

                if (i % 5 == 0)
                {
                    Deck[i].Suit = x0;
                    Deck[i].Num = x1;
                    i--;
                    Deck[i].Suit = x2;
                    Deck[i].Num = x3;
                    i--;
                    Deck[i].Suit = y0;
                    Deck[i].Num = y1;
                    i--;
                    Deck[i].Suit = y2;
                    Deck[i].Num = y3;
                    i += 5;

                }
            }
        }

        public string OutCard(int i) //функция вывода карты и масти
        {
            string answer;
            switch (Deck[i].Num) //вывод карты
            {
                case 11:
                    answer = "Валет";
                    break;
                case 12:
                    answer = "Дама";
                    break;
                case 13:
                    answer = "Король";
                    break;
                case 14:
                    answer = "Туз";
                    break;
                default:
                    answer = Deck[i].Num.ToString(); //преобразуем Num в строковое представление
                    break;
            }
            switch (Deck[i].Suit) //вывод масти
            {
                case 1:
                    answer += " черва";
                    break;
                case 2:
                    answer += " бубна";
                    break;
                case 3:
                    answer += " трефа";
                    break;
                case 4:
                    answer += " пика";
                    break;
            }
            return answer; //возвращаем получившееся значение
        }
    }
    class Card //Класс карт
    {
        public int Suit; //переменная масти
        public int Num; //переменная карты
        public Card(int i, int j) //конструктор
        {
            this.Suit = i;
            this.Num = j;
        }
    }
    class Program
    {
        public static void Main()
        {
            int number;
            Cards A = new Cards();
            number = Convert.ToInt32(Console.ReadLine()); //вводим значение с клавиатуры
            Console.WriteLine(A.OutCard(number)); //вывод карты по номеру
            A.Sort(); //Вызов ф-ии сортировки
            for (int i = 1; i <= 36; i++)
            {
                Console.WriteLine(A.OutCard(i)); //Вызов ф-ии вывода карт
            }
            Console.ReadKey();
        }
    }
}