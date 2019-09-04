#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("stack.out", "w", stdout);
    freopen("stack.in", "r", stdin);
    int  n;
    scanf("%d",&n);
    int  *mas=(int*)malloc(sizeof(int)*n),curr=-1;
    char  t;
    for(int  i=0;i<n;i++)
    {
        scanf("\n%c",&t);
        switch (t)
        {
            case '-':
                printf("%d\n",mas[curr--]);
                break;
            case '+':
                scanf(" %d",&mas[++curr]);
                break;
            default:
                return -2;
        }
    }
    return 0;
}
