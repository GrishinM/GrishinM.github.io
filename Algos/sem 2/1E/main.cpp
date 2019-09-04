#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>
#include <queue>

using namespace std;

list<int> *mas;
queue<int> w;
int *q;
int n,u;

bfs(int i)
{
    w.push(i);
    while(w.size()!=0)
    {
        u=w.front();
        w.pop();
        for(list<int>::const_iterator it=mas[u].cbegin();it!=mas[u].cend();it++)
        {
            if(q[*it]==-1)
            {
                q[*it]=q[u]+1;
                w.push(*it);
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("pathbge1.in");
    ofstream ofs("pathbge1.out");
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
    for(i=1;i<n+1;i++)    q[i]=-1;
    q[1]=0;
    bfs(1);
    for(i=1;i<n+1;i++)    ofs<<q[i]<<" ";
    return 0;
}
