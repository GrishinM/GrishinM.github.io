#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("queue.out", "w", stdout);
    freopen("queue.in", "r", stdin);
    int  n;
    scanf("%d",&n);
    int  *mas=(int*)malloc(sizeof(int)*n),head=0,tail=-1;
    char  t;
    for(int  i=0;i<n;i++)
    {
        scanf("\n%c",&t);
        switch (t)
        {
            case '-':
                printf("%d\n",mas[head++]);
                break;
            case '+':
                scanf(" %d",&mas[++tail]);
                break;
            default:
                return -2;
        }
    }
    return 0;
}
