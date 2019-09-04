#include <stdio.h>
#include <stdlib.h>
#include "par.h"

int main()
{
    int  x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    float  p=perim(x1,y1,x2,y2,x3,y3,x4,y4),s=plos(x1,y1,x2,y2,x3,y3,x4,y4);
    struct  paral  paral0=f(x1,y1,x2,y2,x3,y3,x4,y4,p,s);
    printf("perimetr=%.2f\n",paral0.perimetr);
    printf("ploschad=%.2f\n",paral0.ploschad);
}
