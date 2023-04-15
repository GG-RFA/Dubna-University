
#include <iostream>
#include <thread>
#include <cstring>
using namespace std;
/* (второе задание)
void f1(string str) {
    cout << str << endl;
}
void f2(int* a, const int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ' << endl;
}
*/
/* (первое задание)
void f(int *n) {
    (*n)++;
    for (int i = 0; i < 1; i++)
    cout << "Привет, ИВТ-41" << *n << endl;
}
*/
void f3(int i) {
    cout << "Поток номер=" << i << endl;
}
void f4(int n) {
    thread a[3];
    for (int i = 0; i < n; i++)
        a[i] = thread(f3, i);
    for (int i=0;i<3;i++)
        if (a[i].joinable())
            a[i].join();
}
int main()
{
    setlocale(LC_ALL, "Russian");
    f4(3);
    /* (второе задание)
    string txt = "Привет, ИВТ-41";
    const int n = 8;
    int a[n] = {1,3,-7,8,0,6}; 
    thread t2(f2, a, n);
    thread t1(f1, txt);
    if (t2.joinable())
    t2.join();
    if(t1.joinable())
    t1.join();
    */
    
    /* (первое задание)
    int n = 5;
    thread mythread(f,&n);
    if (mythread.joinable())
    mythread.join();
    cout << n << endl;
    */
    return 0;
}

