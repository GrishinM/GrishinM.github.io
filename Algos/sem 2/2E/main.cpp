#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>

using namespace std;

list<int> *mas;
int *q;
int *r;
int j=0,f,n;
ofstream ofs("hamiltonian.out");

int  dfs(int i)
{
    switch(q[i])
    {
    case 0:
        q[i]=1;
        for(list<int>::const_iterator it=mas[i].cbegin();it!=mas[i].cend();it++)    dfs(*it);
        q[i]=2;
        r[++j]=i;
        break;
    case 1:
        //ofs<<"-1";
        //exit(0);
        break;
    case 2:
        break;
    }
}

bool check()
{
    for(int y=n;y>1;y--)
    {
        f=0;
        for(list<int>::const_iterator it=mas[r[y]].cbegin();it!=mas[r[y]].cend();it++)    if(*it==r[y-1])    f=1;
        if(f==0)    return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("hamiltonian.in");
    int m,i,x,y;
    ifs>>n>>m;
    mas=new list<int>[n+1];
    for(i=0;i<m;i++)
    {
        ifs>>x>>y;
        mas[x].push_back(y);
    }
    q=new int[n+1];
    r=new int[n+1];
    for(i=1;i<n+1;i++)    q[i]=0;
    for(i=1;i<n+1;i++)    dfs(i);
    ofs<<(check()?"YES":"NO");
    return 0;
}
