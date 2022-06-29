#include <iostream>
#include <conio.h>
using namespace std;
//void Space(char*);

void  Space(char* str1)   // Функция сжатия строк с любым количеством пробелов (в пределах размера массива)
{
    char str2[50]; // задаем массив и его размер
    int count = 0;

    for (int i = 0; str1[i] != '\0'; i++) //если не конец строки, то добавляем элементы массива дальше
    {
        if (str1[i] != ' ' && str1[i] !='\t')
        {
            str2[count] = str1[i];
            count++;
        }
        else if ( str1[i] == ' ' && str1[i - 1] != ' ')
        {
            str2[count] = ' ';
            count++;
        }
        else if (str1[i] == '\t')
        {
            str2[count] = str1[i];
            count--;
        }
    }

    str2[count] = '\0';
    cout << str2;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char string[] = "                    \t Перестань                 \t    шакалить                           \t    пожалуйста                ";
    cout << "Строка до сжатия :\n ";
    cout << string;
    cout << endl << "Строка после сжатия :\n";
    Space(string); // передаем массив для сжатия
    _getch();
    return 0;
}


