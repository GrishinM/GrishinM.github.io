#ifndef H_PAR
#define H_PAR
#include <math.h>

struct  paral
{
    int  x1,y1,x2,y2,x3,y3,x4,y4;
    float  perimetr;
    float  ploschad;
};

float  perim(int  x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    return  (sqrt(pow((x1-x2),2) + pow((y1-y2),2))+sqrt(pow((x1-x3),2) + pow((y1-y3),2)))*2;
}

float  plos(int  x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    return  (sqrt(pow((x1-x2),2) + pow((y1-y2),2)))*(sqrt(pow((x1-x3),2) + pow((y1-y3),2)))*(sqrt(1-pow((((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1))/(sqrt(pow((x1-x2),2) + pow((y1-y2),2))*(sqrt(pow((x1-x3),2) + pow((y1-y3),2))))),2)));
}

struct paral f(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,float p,float s)
{
    struct  paral  paral0={x1,y1,x2,y2,x3,y3,x4,y4,p,s};
    return  paral0;
}

#endif
