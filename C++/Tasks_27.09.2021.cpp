
#include <iostream>
#include <cstdlib>
#include <thread>
using namespace std;

class A {
public:
    void operator()(int a[],int len) 
    {
        for (int i = 0; i < len; i++) 
        {
            for (int i = 0; i < 1000000; i++);
            a[i] *= 2;
        }
    }
    void B(int a[], int len) {
        for (int i = 0; i < len; i++) 
        {
            for (int i = 0; i < 1000000; i++);
            a[i] = 9;
        }
    }
};
int main()
{
    const int length = 5;
    int a[length] = { 1,2,3,4,5 };
    A obj;
    thread a_thread(obj, a, length);
    thread b_thread(&A::B, &obj, a, length);
    if (a_thread.joinable()) {
        a_thread.join();
    }
    if (b_thread.joinable()) {
        b_thread.join();
    }
    for (int i = 0; i < length; i++) 
    {
        cout << a[i] << "\t";
    }
    
    return 0;
}