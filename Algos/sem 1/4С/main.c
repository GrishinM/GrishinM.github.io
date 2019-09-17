#include <stdio.h>
#include <stdlib.h>
char mas[10000];
int check(char s[]){
    int n=strlen(s);
    int curr=-1;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='[' || s[i]=='(')
            mas[++curr]=s[i]=='['?']':')';
        else{
            if (s[i]!=mas[curr--])
                return 0;
        }
    }
    return curr==-1?1:0;
}
int main()
{
    freopen("brackets.out", "w", stdout);
    freopen("brackets.in", "r", stdin);
    char s[10000];
    while (gets(s)!=NULL){
        printf(check(s)?"YES\n":"NO\n");
    }
    return 0;
}
