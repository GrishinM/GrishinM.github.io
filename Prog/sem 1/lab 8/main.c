#include <stdio.h>
#include <stdlib.h>

int main()
{
    char  a[99999], b[99999], g[99999];
    gets(a);
    gets(b);
    int  n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            printf("1>2\n");
            break;
        }
        if(b[i]>a[i])
        {
            printf("2>1\n");
            break;
        }
    }
    if(i==n)
    {
        printf("=\n");
    }

    for(int p=0;p<strlen(b);p++)
    {
        g[p]=b[p];
    }
    int  p,c=strlen(b);
    for(p=c;p<(c+n);p++)
    {
        g[p]=a[p-c];
    }
    puts(g);

    char  y;
    scanf("\n%c",&y);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]==y)
        {
            printf("%d",i+1);
            break;
        }
    }
    if(i==strlen(a))
    {
        printf("no");
    }

    int  d[255];
    for(i=0;i<256;i++)
    {
        d[i]=0;
    }
    for(i=0;i<strlen(a);i++)
    {
        d[(int)a[i]]++;
    }
    for(i=0;i<strlen(b);i++)
    {
        d[(int)b[i]]=0;
    }
    int  k=0;
    for(i=0;i<256;i++)
    {
        k+=d[i];
    }
    printf("\n%d\n",k);

    for(i=0;i<256;i++)
    {
        d[i]=-1;
    }
    for(i=0;i<strlen(a);i++)
    {
        d[(int)a[i]]=i;
    }
    for(i=0;i<strlen(b);i++)
    {
        printf(d[(int)b[i]]==-1?"%c - no\n":d[(int)b[i]]==-2?"":"%c - %i\n",b[i],d[(int)b[i]]+1);
        d[(int)b[i]]=-2;
    }
}
