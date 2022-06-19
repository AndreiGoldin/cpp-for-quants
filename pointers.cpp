#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    int* pa;
    a = 13;
    b = 15;
    // pa = &a;
    // *pa = a;

    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "pa = " << pa << endl;
    cout << "*pa = " << *pa << endl;
    cout << "&*pa = " << &*pa << endl;
    cout << "*&a = " << *&a << endl;

    *pa = 14;

    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "pa = " << pa << endl;
    cout << "*pa = " << *pa << endl;
    cout << "&*pa = " << &*pa << endl;
    cout << "*&a = " << *&a << endl;

    pa = &b;

    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "pa = " << pa << endl;
    cout << "*pa = " << *pa << endl;
    cout << "&*pa = " << &*pa << endl;
    cout << "*&a = " << *&a << endl;
}