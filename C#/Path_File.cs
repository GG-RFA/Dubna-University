using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

        }
        static void lab7()
        {
            string path = @"C:\Users\User\Desktop\Новый текстовый документ.txt";  //указываем путь к файлу
            Stack<string> stack = new Stack<string>();
            string line = File.ReadAllText(path, Encoding.Default);
            string[] words = line.Split(new string[] { " ", "\r\n", "\t" }, StringSplitOptions.RemoveEmptyEntries);
            int maxlength = 0;
            for (int i = 0; i < words.Length; i++)
                if (maxlength < words[i].Length) maxlength = words[i].Length;
            for (int i = 0; i < words.Length; i++)
            {
                if (words[i].Length == maxlength && !stack.Contains(words[i])) stack.Push(words[i]);
            }
            string[] maxwords = stack.ToArray();
            int count;
            for (int i = 0; i < maxwords.Length; i++)
            {
                count = 0;
                foreach (string x in words)
                {
                    if (x == maxwords[i]) ++count;
                }
                Console.WriteLine("{2}. Самое длинное слово: {0}\n   Число повторении: {1}", maxwords[i], count, i);
            }
            Console.ReadKey(true);
        }
    }
}
