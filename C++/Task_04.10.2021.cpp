#include <iostream>
#include <math.h>
using namespace std;
int gauss1(double* a, double* b, int n)//прямой ход 
{
    int kk = 0; // kk - номер текущего диагонального элемента
    int n1 = n + 1; // n1 - расстояние между двумя соседними даигональными элементами
    int kn = n; // kn - номер первого элемента следующей обрабатываемой строки
    double s;
    int k, ik, ij, kj, i; // k - текущий номер обрабатываемой строки
    for (k = 0; k < n; k++) 
    {
        for (ik = kk + n, i = k + 1; i < n; ik += n, i++) 
        {
            s = a[ik] / a[kk];
            for (ij = ik + 1, kj = kk + 1; kj < kn; ij++, kj++) 
            {
                a[ij] -= s * a[kj];
                b[i] -= s * b[k];
            }
        }
        kk += n1;
        kn += n;
    }
    return 0;
}

int gauss2(double* a, double* b, int n) // обратный ход
{ 
    int kk = n * n - 1; // kk - номер диагонального элемента a[kk]
    int n1 = n + 1; // n1 - шаг диагонали
    double s;
    int k, kj, j;
    // Вектор решения накладывается на столбец свободных членов
    for (k = n - 1; k >= 0; k--) 
    {
        s = 0;
        for (kj = kk + 1, j = k + 1; j < n; kj++, j++)
            s += a[kj] * b[j];
        b[k] = (b[k] - s) / a[kk];
        kk -= n1;
    }
    return 0;
}

int main()
{
    double a[] = { 2, 3, 4, 5, 0, 6, 7, 8, 0, 0, 9, 10, 0, 0, 0, 11 };
    double b[] = { 40, 65, 67, 44 };
    const int n = 4;
    cout << gauss2(a, b, n) << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << "\t";
        cout << "\n";
    }
}


