#include <stdio.h>
#include <stdlib.h>
#include <math.h>
enum  autom
{
    legc,
    gruz,
    bus,
    race
};

struct  okr
{
    int  centrx;
    int  centry;
    int  radius;
    float  perimetr;
    float  ploschad;
};

union
{
    unsigned int t;
    struct
    {
      unsigned int NumLock :1;
      unsigned int CapsLock :1;
      unsigned int ScrollLock :1;
    }bit;
}klav;

int main()
{
    enum  autom  a,b,c,d;
    a=legc;
    b=gruz;
    c=bus;
    d=race;
    printf("%d\n",c);
    int  x=5,y=6,r=2;
    float  p=2*M_PI*r,s=M_PI*r*r;
    struct okr okr1={x,y,r,p,s};
    printf("ploschad=%f\n",okr1.ploschad);

    unsigned  int  u;
    scanf("%x", &u);
    klav.t=u;
    (klav.bit.NumLock==1) ? printf("NumLock on\n") : printf("NumLock off\n");
    (klav.bit.CapsLock==1) ? printf("CapsLock on\n") : printf("CapsLock off\n");
    (klav.bit.ScrollLock==1) ? printf("ScrollLock on\n") : printf("ScrollLock off\n");
}
