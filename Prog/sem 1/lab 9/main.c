#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  n,i,m=0,p,j;
    scanf("%d",&n);
    for(i=1;i<n+1;i++)
    {
        if(n%i==0) m+=1;
    }
    if(m!=2)
    {
        while(p!=2)
        {
            p=0;
            for(i=1;i<n+1;i++)
            {
                if(n%i==0) p+=1;
            }
            if(p=2)
            {
                break;
            }
            n=n-1;
        }
    }
    for(i=2;i<n+1;i++)
    {
        p=0;
        for(j=1;j<i+1;j++)
        {
            if(i%j==0) p+=1;
        }
        if(p==2) printf("%d  ",i);
    }
    printf("\n");
    float  a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    printf("\n");
    for(i=0;i<a;i++)
    {
        c*=1+(b/100);
        printf("%.2f\n",c);
    }
}
