#include <stdio.h>
#include <stdlib.h>
char b[99999];
int  sumd(int b)
{
    if(b<10)
    {
        return b;
    }
    else
    {
        return b%10+sumd(b/10);
    }
}
void  ud()
{
    int i,m=0;
    if((b[strlen(b)-1]==' ')&&(b[strlen(b)-2]=='.'))
    {
        b[strlen(b)-1]=0;
    }
    if(b[0]=='"')
    {
        m=1;
    }
    for(i=1;i<strlen(b);i++)
    {
        if(b[i]=='"')
        {
            if(m==0)
            {
                m++;
            }
            else
            {
                m--;
            }
        }
        if((b[i]==' ')&&((b[i-1]==' ')||(b[i-1]=='(')||((b[i-1]=='"')&&(m==1))))
        {
            break;
        }
    }
    if(i!=strlen(b))
    {
        for(;i<strlen(b);i++)
        {
            b[i]=b[i+1];
        }
        ud(b);
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",sumd(a));
    scanf("\n");
    gets(b);
    ud();
    puts(b);
}
