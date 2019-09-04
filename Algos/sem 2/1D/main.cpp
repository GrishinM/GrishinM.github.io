#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>

using namespace std;

list<int> *mas;
int *q;
int j,n;

int  dfs(int i)
{
    for(list<int>::const_iterator it=mas[i].cbegin();it!=mas[i].cend();it++)
        if(q[*it]==0)
        {
            q[*it]=q[i];
            dfs(*it);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("components.in");
    ofstream ofs("components.out");
    int m,i,x,y;
    ifs>>n>>m;
    mas=new list<int>[n+1];
    for(i=0;i<m;i++)
    {
        ifs>>x>>y;
        mas[x].push_back(y);
        mas[y].push_back(x);
    }
    q=new int[n+1];
    int u=0;
    for(i=1;i<n+1;i++)    q[i]=0;
    for(i=1;i<n+1;i++)
    {
        if (q[i]==0)
        {
            q[i]=++u;
            dfs(i);
        }
    }
    ofs<<u<<endl;
    for(i=1;i<n+1;i++)    ofs<<q[i]<<" ";
    return 0;
}
