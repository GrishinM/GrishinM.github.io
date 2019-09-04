#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define PI 3.14159265

using namespace std;
// Интерфейс "Геометрическая фигура".
class IGeoFig
{
public:
    // Площадь.
    virtual double square() = 0;
    // Периметр.CVector2D r
    virtual double perimeter() = 0;
};
// Вектор
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
// Интерфейс "Физический объект".
class IPhysObject
{
public:
    // Масса, кг.
    virtual double mass() const = 0;
    // Координаты центра масс, м.
    virtual CVector2D position() = 0;
    // Сравнение по массе.
    bool operator== ( const IPhysObject& ob ) const
    {
        return mass() == ob.mass();
    }
    // Сравнение по массе.
    bool operator< ( const IPhysObject& ob ) const
    {
        return mass() < ob.mass();
    }
};
// Интерфейс "Отображаемый"
class IPrintable
{
public:
    // Отобразить на экране
    // (выводить в текстовом виде параметры фигуры).
    virtual void draw() = 0;
};
// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable
{
    // Задать параметры объекта с помощью диалога с пользователем.
    virtual void initFromDialog() = 0;
};
// Интерфейс "Класс"
class BaseCObject
{
public:
    // Имя класса (типа данн
    virtual const char* classname() = 0;
    // Размер занимаемой памяти.
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
        cout<<"Тип: "<<classname()<<"    Масса: "<<mass()<<"    Координаты центра: "<<pos.x<<" "<<pos.y<<"    Сторона 1: "<<side1<<"    Сторона 2: "<<side2<<endl;
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
        cout<<"Введите массу"<<endl;
        cin>>mas;
        cout<<"Введите координаты центра"<<endl;
        cin>>pos.x>>pos.y;
        cout<<"Введите стороны"<<endl;
        cin>>side1>>side2;
    }
    const char* classname()
    {
        return "прямоугольник";
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
        cout<<"Тип: "<<classname()<<"    Масса: "<< mass()<<"    Координаты центра: "<<pos.x<<" "<<pos.y<<"    Сторона 1: "<<side1<<"    Сторона 2: "<<side2<<"    Меньший угол: "<<angle<<endl;
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
        cout<<"Введите массу"<<endl;
        cin>>mas;
        cout<<"Введите координаты центра"<<endl;
        cin>>pos.x>>pos.y;
        cout<<"Введите стороны"<<endl;
        cin>>side1>>side2;
        cout<<"Введите угол"<<endl;
        cin>>angle;
    }
    const char* classname()
    {
        return "параллелограмм";
    }
    unsigned size()
    {
        return sizeof(*this);
    }
};

int main()
{
    system("chcp 1251");
    cout<<"Команды:"<<endl<<"1 - добавить прямоугольник"<<endl<<"2 - добавить параллелограмм"<<endl<<"3 - отобразить все фигуры"<<endl<<"4 - суммарная площадь всех фигур"<<endl;
    cout<<"5 - суммарный периметр всех фигур"<<endl<<"6 - центр масс всей системы"<<endl<<"7 - память, занимаемая всеми экземплярами классов"<<endl<<"8 - сортировка фигур по массе"<<endl;
    cout<<"9 - выход"<<endl;
    int x;
    double z;
    vector<figure*> a;
    rectangle *c;
    parallelogram *d;
    CVector2D r(0,0);
    while(true)
    {
        cout<<endl<<"Введите команду"<<endl;
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
            cout<<"Площадь фигур = "<<z<<" квадратных метров"<<endl<<endl;
            break;
        case 5:
            z=0;
            for(auto k:a)    z+=k->perimeter();
            cout<<"Периметр фигур = "<<z<<" метров"<<endl;
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
            cout<<"Центр масс системы: "<<r.x<<" "<<r.y<<endl;
            break;
        case 7:
            z=0;
            for(auto k:a)    z+=k->size();
            cout<<"Память = "<<z<<" байт"<<endl<<endl;
            break;
        case 8:
            sort(a.begin(), a.end(), [](figure* l, figure* r){return *l < *r;});
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"Команда не существует"<<endl;
            break;
        }
    }
    return 0;
}
