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
    cout<<"���������:"<<endl<<"0 - vechile"<<endl<<"1 - car"<<endl<<"�������:"<<endl<<"1 - ������ ������"<<endl;
    cout<<"2 - �������� ������ ��������"<<endl<<"3 - ��������� ������ ��������"<<endl<<"4 - ������� ������ ��������"<<endl;
    cout<<"5 - �����������"<<endl<<"6 - ������� �������"<<endl<<"��� ������:"<<endl<<"7 - �������� ���-�� �������"<<endl;
    cout<<"8 - ��������� ���-�� �������"<<endl<<"9 - ����������� ������� �������"<<endl;
    while(1)
    {
        cout<<endl<<"�������� ���������"<<endl;
        cin>>u;
        cout<<"������� �������"<<endl;
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"������� ����������"<<endl;
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
            cout<<"������� ������"<<endl;
            cin>>n;
            if(!u)    a.setk(n);
            else    b.setk(n);
            break;
        case 5:
            cout<<"������� �����"<<endl;
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
            else    cout<<"������������ ��� ����������"<<endl;
            break;
        case 8:
            if(u)
            {
                cout<<"������� ������"<<endl;
                cin>>n;
                b.upfuel(n);
            }
            else    cout<<"������������ ��� ����������"<<endl;
            break;
        case 9:
            if(u)
            {
                cout<<"������� ������"<<endl;
                cin>>t;
                b.seth(t);
            }
            else    cout<<"������������ ��� ����������"<<endl;
            break;
        default:
            cout<<"�������������� �������"<<endl;
        }
    }
}
