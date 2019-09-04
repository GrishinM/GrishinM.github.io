#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>
#include <list>

using namespace std;

list<int> *mas;
int *q;
int u,n;
ofstream ofs("bipartite.out");
stack<int> a;

int  dfs(int i, int c)
{
    if(!q[i])
    {
        q[i]=c;
        for(list<int>::const_iterator it=mas[i].cbegin(); it!=mas[i].cend(); it++)
        {
            dfs(*it, (q[i]%2)+1);
        }
    }
}

bool check()
{
    for(int j=1; j<n+1; j++)
    {
        for(list<int>::const_iterator it=mas[j].cbegin(); it!=mas[j].cend(); it++)
        {
            if(q[j]==q[*it])    return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("bipartite.in");
    int m,i,x,y;
    ifs>>n>>m;
    mas=new list<int>[n+1];
    for(i=0; i<m; i++)
    {
        ifs>>x>>y;
        mas[x].push_back(y);
        mas[y].push_back(x);
    }
    q=new int[n+1];
    for(int j=1; j<n+1; j++)    q[j]=0;
    for(int j=1; j<n+1; j++)    dfs(j, 1);
    ofs<<((check()==1)?"YES":"NO");
    return 0;
}
