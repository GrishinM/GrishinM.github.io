#include <iostream>
#include "vechile.h"

using namespace std;

int main()
{
    system("chcp 1251");
    vechile a;
    car b;
    vector q;
    int n,x,u;
    double t;
    cout<<"Транспорт:"<<endl<<"0 - vechile"<<endl<<"1 - car"<<endl<<"Команды:"<<endl<<"1 - задать вектор"<<endl;
    cout<<"2 - включить запись маршрута"<<endl<<"3 - выключить запись маршрута"<<endl<<"4 - частота записи маршрута"<<endl;
    cout<<"5 - переместить"<<endl<<"6 - вывести маршрут"<<endl<<"Для машины:"<<endl<<"7 - получить кол-во бензина"<<endl;
    cout<<"8 - пополнить кол-во бензина"<<endl<<"9 - коэффициент расхода бензина"<<endl;
    while(1)
    {
        cout<<endl<<"Выберите транспорт"<<endl;
        cin>>u;
        cout<<"Введите команду"<<endl;
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"Введите координаты"<<endl;
            cin>>q.x>>q.y>>q.z;
            if(!u)    a.setvec(q);
            else    b.setvec(q);
            break;
        case 2:
            if(!u)    a.on();
            else    b.on();
            break;
        case 3:
            if(!u)    a.off();
            else    b.off();
            break;
        case 4:
            cout<<"Введите данные"<<endl;
            cin>>n;
            if(!u)    a.setk(n);
            else    b.setk(n);
            break;
        case 5:
            cout<<"Введите время"<<endl;
            cin>>n;
            if(!u)    a.go(n);
            else    b.go(n);
            break;
        case 6:
            cout<<endl;
            if(!u)    a.print();
            else    b.print();
            break;
        case 7:
            if(u)    cout<<b.getfuel()<<endl;
            else    cout<<"Неправильный вид транспорта"<<endl;
            break;
        case 8:
            if(u)
            {
                cout<<"Введите данные"<<endl;
                cin>>n;
                b.upfuel(n);
            }
            else    cout<<"Неправильный вид транспорта"<<endl;
            break;
        case 9:
            if(u)
            {
                cout<<"Введите данные"<<endl;
                cin>>t;
                b.seth(t);
            }
            else    cout<<"Неправильный вид транспорта"<<endl;
            break;
        default:
            cout<<"Несуществующая команда"<<endl;
        }
    }
}
