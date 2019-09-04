#ifndef VECHILE_H_INCLUDED
#define VECHILE_H_INCLUDED
#include <cmath>
using namespace std;

struct vector
{
    double x=0,y=0,z=0;
    bool operator==(const vector &t)
    {
        if(x==t.x && y==t.y && z==t.z)    return true;
        else    return false;
    }
    bool operator!=(const vector &t)
    {
        return !(*this==t);
    }
    void operator+=(const vector &t)
    {
        x+=t.x;
        y+=t.y;
        z+=t.z;
    }
};

class vechile
{
protected:
    vector x;
    vector rad;
    int t;
    int g;
    int size;
    vector *road;
    int iter;
    int k;
public:
    vechile();
    vechile(const vechile &klass);
    bool operator==(const vechile &klass);
    bool operator!=(const vechile &klass);
    void setvec(vector a);
    void setk(int a);
    void off();
    void on();
    void go(int a);
    void print();
};

class car : public vechile
{
private:
    double fuel;
    double cost;
    double h;
public:
    car();
    car(const car &klass);
    bool operator==(const car &klass);
    bool operator!=(const car &klass);
    double getfuel();
    void upfuel(double a);
    void seth(double a);
    void go(int a);
};

#endif // VECHILE_H_INCLUDED
