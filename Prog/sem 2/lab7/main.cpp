#include <iostream>
#include "matr.h"

using namespace std;

template <class T>
void cre(int a, int b)
{
    T **q = new T *[a];
    for(int i = 0; i < a; i++)    q[i] = new T[b];
    cout << "¬ведите элементы матрицы" << endl;
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
            cin >> q[i][j];
    matr<T> e(a, b, q);
    int x, y;
    while(true)
    {
        cout << endl << "¬ведите индекс" << endl;
        cin >> x >> y;
        try
        {
            e.el(x, y);
        }
        catch(const char *str)
        {
            cout << str << endl;
        }
    }
}

int main()
{
    system("chcp 1251");
    int a, b;
    cout << "¬ведите тип элементов матрицы" << endl;
    char k;
    cin >> k;
    cout << "¬ведите размер матрицы" << endl;
    cin >> a >> b;
    switch(k)
    {
    case 'i':
        cre<int>(a, b);
        break;
    case 'f':
        cre<float>(a, b);
        break;
    }
}
