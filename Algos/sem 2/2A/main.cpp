#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>

using namespace std;

list<int> *mas;
int *q;
int *r;
int j=0;
ofstream ofs("topsort.out");

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
        ofs<<"-1";
        exit(0);
        break;
    case 2:
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("topsort.in");
    int n,m,i,x,y;
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
    for(i=n;i>0;i--)    ofs<<r[i]<<" ";
    return 0;
}
