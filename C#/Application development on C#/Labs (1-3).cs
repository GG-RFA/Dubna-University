using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
           
        }

        static void lab1()
        {
            double z1, z2;
            double b = 5;
            z1 = Math.Sqrt(2 * b + 2 * Math.Sqrt(Math.Pow(b, 2) - 4)) / (Math.Sqrt(Math.Pow(b, 2) - 4) + b + 2);
            z2 = 1 / Math.Sqrt(b + 2);
            Console.WriteLine(z1);
            Console.WriteLine(z2);
            Console.ReadKey();
        } 
        static void lab21()
        {
            double R, x, y;
            Console.Write("Введите R: ");
            R = Convert.ToDouble(Console.ReadLine());
            Console.Write("Введите x: ");
            x = Convert.ToDouble(Console.ReadLine());
            y = 0;
            double p1x, p2x, p3x, p4x, p5x, p6x, p7x;
            p3x = -4;
            p2x = p3x - 2;
            p1x = p2x - 1;
            p4x = -R;
            p5x = 0;
            p6x = R;
            p7x = p6x + 1;
            if (x > p3x && x < p4x)
            {
                y = Math.Sqrt(R * R - (x - p4x) * (x - p4x));
            }
            else if (x == p4x)
            {
                y = R;
            }
            else if (x > p4x && x < p5x)
            {
                y = Math.Sqrt(Math.Pow(R, 2) - Math.Pow(x, 2));
            }
            else if (x == p5x)
            {
                y = R;
            }
            else if (x > p5x && x < p6x)
            {
                y = Math.Sqrt(R * R - (x - p6x) * (x - p6x));
            }
            else if(x == p6x)
            {
                y = -R;
            }
            
            Console.WriteLine(y);
            Console.ReadKey();
        }

          static void lab22()
          {
               Console.Write("Введите r:");
            double r = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите координаты:");
            Console.Write("Введите x:");
            double x = double.Parse(Console.ReadLine());
            Console.Write("Введите y:");
            double y = double.Parse(Console.ReadLine());
            if (Math.Sqrt(x*x + y*y) <= r)
            {
                if ((x <= 0 && x <= y) || (y <= 0 && y <= x))
                {
                    Console.WriteLine("Да");
                }
                else Console.WriteLine("Нет");
            }
            else Console.WriteLine("Нет");

            Console.WriteLine();
            Console.ReadKey();
          }
           static void lab31()
           {
            double y = 0;
            for (int x = -7; x <= 3; x++)
            {
                if (x >= -7 && x <= -6) y = 1;
                if (x >= -5 && x <= -4) y = -4 - 0.9 * x;
                if (x >= -4 && x <= 0) y = Math.Sqrt(2 * 2 - (x + 2) * (x + 2));
                if (x >= 0 && x <= 2) y = Math.Sqrt(1 - (x - 1) * (x - 1));
                if (x >= 2 && x <= 3) y = 2 - x;
                Console.WriteLine("x=" + x + "\t y=" + y);
            }
            Console.ReadKey();
        }
        
          static void lab32()
          {
           for (int i = 1; i <= 10; i++)
            {
                Console.Write("Введите r:");
                double r = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("Введите координаты для {0}-го выстрела:",i);
                Console.Write("Введите x:");
                double x = double.Parse(Console.ReadLine());
                Console.Write("Введите y:");
                double y = double.Parse(Console.ReadLine());
                if (Math.Sqrt(x * x + y * y) <= r)
                {
                    if ((x <= 0 && x <= y) || (y <= 0 && y <= x))
                    {
                        Console.WriteLine("Попал в мишень");
                    }
                    else Console.WriteLine("Не попал в мишень");
                }
                else Console.WriteLine("Не попал в мишень");

                Console.WriteLine();
                Console.ReadKey();
            }
          }
    }
}
