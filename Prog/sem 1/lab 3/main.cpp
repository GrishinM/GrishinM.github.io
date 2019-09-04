#include <iostream>
#include <math.h>

using namespace std;
int todec(char *a,int osn,int last)
{
    int n=1,sum=0;
    for (int i=last;i>=0;--i)
    {
        sum+=((a[i]>47&&a[i]<58)?a[i]-48:a[i]-55)*n;
        n<<=osn;
    }
    return sum;
}
int main()
{
    char *in1=new char[100];
    int len1=0;
    scanf("%c",&in1[len1]);
    while (in1[len1]!='\n')
    {
        scanf("%c",&in1[++len1]);
    }
    --len1;
    int a=todec(in1,3,len1);
    printf("%X\n",a);
    printf("%X\n",a<<4);
    printf("%X\n",~a);
    char *in2=new char[100];
    int len2=0;
    scanf("%c",&in2[len2]);
    while (in2[len2++]!='\n')
    {
        scanf("%c",&in2[len2]);
    }
    len2-=2;
    int b=todec(in2,4,len2);
    printf("%X\n",a&b);
}
