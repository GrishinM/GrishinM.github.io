#include "as.h"

mnozh::mnozh(int x)
{
    n = x;
    mas = new int[n];
    for(int i=0; i<n; i++)
        mas[i]=minint;
}

bool mnozh::find(int x)
{
    for(int i=0; i<n; i++)
        if(mas[i]==x)
            return true;
    return false;
}

void mnozh::ins(int x)
{
    if(!find(x))
    {
        for(int i=0; i<n; i++)
            if(mas[i]==minint)
            {
                mas[i]=x;
                return;
            }
    }
}

void mnozh::del(int x)
{
    if(find(x))
    {
        for(int i=0; i<n; i++)
            if(mas[i]==x)
            {
                mas[i]=minint;
                return;
            }
    }
}

void mnozh::print()
{
    for(int i=0; i<n; i++)
        if(mas[i]!=minint)
            cout<<mas[i]<<" ";
    cout<<endl;
}

mnozh* mnozh::operator|(mnozh a)
{
    mnozh *c=new mnozh(n+a.n);
    *c+=a;
    *c+=*this;
    return c;
}

mnozh* mnozh::operator&(mnozh a)
{
    mnozh *c= new mnozh(min(n,a.n));
    for(int i=0; i<n; i++)
        if(a.find(mas[i]))
            c->ins(mas[i]);
    return c;
}

void mnozh::operator+=(mnozh a)
{
    for(int i=0; i<a.n; i++)
        ins(a.mas[i]);
}

void mnozh::operator-=(mnozh a)
{
    for(int i=0; i<a.n; i++)
        del(a.mas[i]);
}

void menu::operator()()
{
    int x=mainview.get();
    switch (x)
    {
    case 10:
        exit(0);
        break;
    case 1:
        create();
        break;
    case 2:
        check();
        break;
    case 3:
        inser();
        break;
    case 4:
        delet();
        break;
    case 5:
        out();
        break;
    case 6:
        cross();
        break;
    case 7:
        unio();
        break;
    case 8:
        unio2();
        break;
    case 9:
        cross2();
        break;
    default:
        cout<<"Несуществующая команда"<<endl;
    }
}

menu::menu(int m)
{

    len=m;
    arr=new mnozh*[len];
    mas = new int[len];
    for(int i=0; i<len; i++)
        mas[i]=0;
}

void menu::create()
{
    wstring s=createview.get(0,1);
    cout<<"Введите номер множества, максимальное и текущее кол-во элементов"<<endl;
    int y,n,x,t;
    cin>>y>>n>>t;
    if(y<0 || y>=len)
    {
        cout<<"Такого множества не может существовать"<<endl;
        return;
    }
    if(mas[y])
    {
        cout<<"Это множество уже существует"<<endl;
        return;
    }
    if(t>n)
    {
        cout<<"Куку?"<<endl;
        return;
    }
    mas[y]=1;
    arr[y]=new mnozh(n);
    if (t)
        cout<<"Введите элементы множества "<<y<<endl;
    for(int i=0; i<t; i++)
    {
        cin>>x;
        arr[y]->ins(x);
    }
}

void menu::check()
{
    cout<<"Введите номер множества и число"<<endl;
    int x,y;
    cin>>x>>y;
    assert(x);
    cout<<"Элемент "<<(arr[x]->find(y)?"":"не ")<<"найден"<<endl;;
}

void menu::inser()
{
    cout<<"Введите номер множества и число"<<endl;
    int x,y;
    cin>>x>>y;
    assert(x);
    arr[x]->ins(y);
}

void menu::delet()
{
    cout<<"Введите номер множества и число"<<endl;
    int x,y;
    cin>>x>>y;
    assert(x);
    arr[x]->del(y);
}

void menu::out()
{
    cout<<"Введите номер множества"<<endl;
    int x;
    cin>>x;
    assert(x);
    cout<<"Элементы множества "<<x<<":"<<endl;
    arr[x]->print();
}

void menu::unio()
{
    cout<<"Введите номера объединяемых множеств и номер множества, где будет их объединение"<<endl;
    int x,y,z;
    cin>>x>>y>>z;
    assert2(x,y);
    arr[z]=(*arr[x])|(*arr[y]);
    mas[z]=1;
}

void menu::cross()
{
    cout<<"Введите номера пересекаемых множеств и номер множества, где будет их пересечение"<<endl;
    int x,y,z;
    cin>>x>>y>>z;
    assert2(x,y);
    arr[z]=(*arr[x])&(*arr[y]);
    mas[z]=1;
}

void menu::unio2()
{
    cout<<"Введите номера множеств"<<endl;
    int x,y;
    cin>>x>>y;
    assert2(x,y);
    (*arr[x])+=(*arr[y]);
}

void menu::cross2()
{
    cout<<"Введите номера множеств"<<endl;
    int x,y;
    cin>>x>>y;
    assert2(x,y);
    *arr[x]-=*arr[y];
}
