#include "vechile.h"
#include <iostream>

vechile::vechile()
{
    t=1;
    g=0;
    iter=0;
    size=1000;
    k=1;
    road=new vector[size];
}

vechile::vechile(const vechile &klass)
{
    x=klass.x;
    t=klass.t;
    g=klass.g;
    k=klass.k;
    rad=klass.rad;
    size=klass.size;
    road=new vector[size];
    for(int i=0;i<size;i++)    road[i]=klass.road[i];
}

bool vechile::operator==(const vechile &klass)
{
    if(x==klass.x && rad==klass.rad && t==klass.t && g==klass.g && k==klass.k && iter==klass.iter)
        for(int i=0;i<size;i++)    if(road[i]!=klass.road[i])    return false;
                                   else    return true;
    else return false;
}

bool vechile::operator!=(const vechile &klass)
{
    return !(*this==klass);
}

void vechile::setvec(vector a)
{
    x=a;
}

void vechile::setk(int a)
{
    k=a;
}

void vechile::off()
{
    t=0;
}

void vechile::on()
{
    t=1;
}

void vechile::go(int a)
{
    if(a && t && k)
    {
        /*vector r;
        r.x=x.x/a;
        r.y=x.y/a;
        r.z=x.z/a;*/
        for(int i=0;i<a;i++)
        {
            g=(g+1)%k;
            rad+=x;
            if(!g)    road[iter++]=rad;
        }

    }
    vector b;
    setvec(b);
}

void vechile::print()
{
    for(int u=0;u<iter;u++)    cout<<road[u].x<<" "<<road[u].y<<" "<<road[u].z<<endl;
}

car::car()
{
    t=1;
    g=0;
    h=0.5;
    iter=0;
    size=1000;
    k=1;
    road=new vector[size];
    fuel=100;
}

car::car(const car &klass)
{
    x=klass.x;
    t=klass.t;
    g=klass.g;
    k=klass.k;
    h=klass.h;
    rad=klass.rad;
    size=klass.size;
    road=new vector[size];
    fuel=klass.fuel;
    for(int i=0;i<size;i++)    road[i]=klass.road[i];
}

bool car::operator==(const car &klass)
{
    if(x==klass.x && rad==klass.rad && t==klass.t && fuel==klass.fuel && g==klass.g && k==klass.k && iter==klass.iter && h==klass.h)
        for(int i=0;i<size;i++)    if(road[i]!=klass.road[i])    return false;
                                   else    return true;
    else return false;
}

bool car::operator!=(const car &klass)
{
    return !(*this==klass);
}

double car::getfuel()
{
    return fuel;
}

void car::upfuel(double a)
{
    fuel+=a;
}

void car::seth(double a)
{
    h=a;
}
void car::go(int a)
{
        int v=sqrt(x.x*x.x+x.y*x.y+x.z*x.z);
        cost=h*v;
        if((fuel-cost*a)>=0)
        {
            fuel-=cost*a;
            if(a && t && k)
            {
                /*vector r;
                r.x=x.x/a;
                r.y=x.y/a;
                r.z=x.z/a;*/
                for(int i=0;i<a;i++)
                {
                    g=(g+1)%k;
                    rad+=x;
                    if(!g)    road[iter++]=rad;
                }

            }
            vector b;
            setvec(b);
        }
        else cout<<"Бензина не хватит"<<endl;
}
