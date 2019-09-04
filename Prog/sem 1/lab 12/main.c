#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    freopen("OUTPUT", "w", stdout);
    int  c=atoi(argv[1])+atoi(argv[2]);
    printf("%d",c);
}
