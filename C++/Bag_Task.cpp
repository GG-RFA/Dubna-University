#include <iostream>
#include <cmath>

using namespace std;

double findansw(int* w, int* v, double* b, int N, int W) {
    //  1.1
    for (int i = 0; i < N; i++)
    {
        b[i] = v[i] / w[i];
    }
    //  1.2
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (b[j] > b[i])// больший вес лучше при одинаковой цене за ед
            {
                double a[] = { b[j],w[j],v[j] };
                b[j] = b[i];
                w[j] = w[i];
                v[j] = v[i];
                b[i] = a[0];
                w[i] = a[1];
                v[i] = a[2];
            }
        }
    }
    //  2
    double L = W;
    //  3
    double S = 0;
    //  4
    for (int i = 0; i < N; i++)
    {
        if (w[i] <= L)
        {
            //b[i] = 0;
            L -= w[i];
            S += v[i];
        }
    }
    return S;
}

int main()
{
    int N = 3;
    int W = 40;
    int w[] = { 20,10,20 };
    int v[] = { 100,60,100 };
    //int b[] = new int [N];
    double b[] = { 0,0,0 };
    double s = 0;
    s = findansw(w, v, b, N, W);
    cout << "s=" << s << endl;
    return 0;
}

