#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define PI 3.14159265

using namespace std;
// ��������� "�������������� ������".
class IGeoFig
{
public:
    // �������.
    virtual double square() = 0;
    // ��������.CVector2D r
    virtual double perimeter() = 0;
};
// ������
class CVector2D
{
public:
    double x, y;
    CVector2D(double a, double b):x(a),y(b){}
    CVector2D operator*(double k)
    {
        CVector2D tmp(x*k, y*k);
        return tmp;
    }
    CVector2D operator/=(double k)
    {
        x/=k;
        y/=k;
        return *this;
    }
    CVector2D operator+=(const CVector2D &a)
    {
        x+=a.x;
        y+=a.y;
        return *this;
    }
};
// ��������� "���������� ������".
class IPhysObject
{
public:
    // �����, ��.
    virtual double mass() const = 0;
    // ���������� ������ ����, �.
    virtual CVector2D position() = 0;
    // ��������� �� �����.
    bool operator== ( const IPhysObject& ob ) const
    {
        return mass() == ob.mass();
    }
    // ��������� �� �����.
    bool operator< ( const IPhysObject& ob ) const
    {
        return mass() < ob.mass();
    }
};
// ��������� "������������"
class IPrintable
{
public:
    // ���������� �� ������
    // (�������� � ��������� ���� ��������� ������).
    virtual void draw() = 0;
};
// ��������� ��� �������, ������� ����� ������ ����� ������ � �������������.
class IDialogInitiable
{
    // ������ ��������� ������� � ������� ������� � �������������.
    virtual void initFromDialog() = 0;
};
// ��������� "�����"
class BaseCObject
{
public:
    // ��� ������ (���� ����
    virtual const char* classname() = 0;
    // ������ ���������� ������.
    virtual unsigned int size() = 0;
};

class figure: public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject{};

class rectangle: public figure
{
private:
    double mas;
    CVector2D pos;
    double side1;
    double side2;
public:
    rectangle():mas(0), pos(CVector2D(0,0)), side1(0), side2(0){};
    void draw()
    {
        cout<<"���: "<<classname()<<"    �����: "<<mass()<<"    ���������� ������: "<<pos.x<<" "<<pos.y<<"    ������� 1: "<<side1<<"    ������� 2: "<<side2<<endl;
    }
    double mass() const
    {
        return mas;
    }
    CVector2D position()
    {
        return pos;
    }
    double perimeter()
    {
        return 2*(side2+side1);
    }
    double square()
    {
        return side2*side1;
    }
    void initFromDialog()
    {
        cout<<"������� �����"<<endl;
        cin>>mas;
        cout<<"������� ���������� ������"<<endl;
        cin>>pos.x>>pos.y;
        cout<<"������� �������"<<endl;
        cin>>side1>>side2;
    }
    const char* classname()
    {
        return "�������������";
    }
    unsigned size()
    {
        return sizeof(*this);
    }
};

class parallelogram: public figure
{
private:
    double mas;
    CVector2D pos;
    double side1;
    double side2;
    double angle;
public:
    parallelogram():mas(0), pos(CVector2D(0,0)), side1(0), side2(0), angle(0){}
    void draw()
    {
        cout<<"���: "<<classname()<<"    �����: "<< mass()<<"    ���������� ������: "<<pos.x<<" "<<pos.y<<"    ������� 1: "<<side1<<"    ������� 2: "<<side2<<"    ������� ����: "<<angle<<endl;
    }
    double mass() const
    {
        return mas;
    }
    CVector2D position()
    {
        return pos;
    }
    double perimeter()
    {
        return 2*(side1+side2);
    }
    double square()
    {
        return side1*side2*sin(angle*PI/180);
    }
    void initFromDialog()
    {
        cout<<"������� �����"<<endl;
        cin>>mas;
        cout<<"������� ���������� ������"<<endl;
        cin>>pos.x>>pos.y;
        cout<<"������� �������"<<endl;
        cin>>side1>>side2;
        cout<<"������� ����"<<endl;
        cin>>angle;
    }
    const char* classname()
    {
        return "��������������";
    }
    unsigned size()
    {
        return sizeof(*this);
    }
};

int main()
{
    system("chcp 1251");
    cout<<"�������:"<<endl<<"1 - �������� �������������"<<endl<<"2 - �������� ��������������"<<endl<<"3 - ���������� ��� ������"<<endl<<"4 - ��������� ������� ���� �����"<<endl;
    cout<<"5 - ��������� �������� ���� �����"<<endl<<"6 - ����� ���� ���� �������"<<endl<<"7 - ������, ���������� ����� ������������ �������"<<endl<<"8 - ���������� ����� �� �����"<<endl;
    cout<<"9 - �����"<<endl;
    int x;
    double z;
    vector<figure*> a;
    rectangle *c;
    parallelogram *d;
    CVector2D r(0,0);
    while(true)
    {
        cout<<endl<<"������� �������"<<endl;
        cin>>x;
        cout<<endl;
        switch(x)
        {
        case 1:
            c = new rectangle;
            c->initFromDialog();
            a.push_back(c);
            break;
        case 2:
            d = new parallelogram;
            d->initFromDialog();
            a.push_back(d);
            break;
        case 3:
            for(auto k:a)    k->draw();
            break;
        case 4:
            z=0;
            for(auto k:a)    z+=k->square();
            cout<<"������� ����� = "<<z<<" ���������� ������"<<endl<<endl;
            break;
        case 5:
            z=0;
            for(auto k:a)    z+=k->perimeter();
            cout<<"�������� ����� = "<<z<<" ������"<<endl;
            break;
        case 6:
            z=0;
            r.x=0;
            r.y=0;
            for(auto k:a)
            {
                r+=(k->position()*k->mass());
                z+=k->mass();
            }
            r/=z;
            cout<<"����� ���� �������: "<<r.x<<" "<<r.y<<endl;
            break;
        case 7:
            z=0;
            for(auto k:a)    z+=k->size();
            cout<<"������ = "<<z<<" ����"<<endl<<endl;
            break;
        case 8:
            sort(a.begin(), a.end(), [](figure* l, figure* r){return *l < *r;});
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"������� �� ����������"<<endl;
            break;
        }
    }
    return 0;
}
