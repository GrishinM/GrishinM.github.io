#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("postfix.out", "w", stdout);
    freopen("postfix.in", "r", stdin);
    char  x;
    int  j=-1,mas[10000],v=0,flag=0;
    while(scanf("%c",&x)!=-1){
        switch(x)
        {
        case '+':
            mas[j-1]+=mas[j];
            break;
        case '-':
            mas[j-1]-=mas[j];
            break;
        case '*':
            mas[j-1]*=mas[j];
            break;
        case ' ':
            if (flag)
                mas[++j]=v;
            v=0;
            flag=0;
            j++;
            break;
        default:
            flag=1;
            j++;
            v=v*10+x-48;
        }
        j--;
    }
    if (flag)
        mas[++j]=v;
    printf("%d",mas[0]);
    return 0;
}
