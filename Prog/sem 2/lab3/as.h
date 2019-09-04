#ifndef AS_H_INCLUDED
#define AS_H_INCLUDED
#define assert(val) \
if(!mas[val] || val<0 || val>=len)\
{\
    cout<<"Такого множества не существует"<<endl;\
    return;\
}
#define assert2(a1,a2) assert(a1);assert(a2);
#include <iostream>

using namespace std;
const int minint = -32000;

class mnozh
{
private:
    int n;
    int *mas;
public:
    mnozh(int x);
    bool find(int x);
    void ins(int x);
    void del(int x);
    void print();
    mnozh *operator|(mnozh a);
    mnozh *operator&(mnozh a);
    void operator+=(mnozh a);
    void operator-=(mnozh a);
};

class menu
{
public:
    void operator()();
    menu(int m);
    view mainview,createview;
private:
    mnozh **arr;
    int *mas;
    int len;
    void create();
    void check();
    void inser();
    void delet();
    void out();
    void unio();
    void cross();
    void unio2();
    void cross2();
};

#endif // AS_H_INCLUDED
