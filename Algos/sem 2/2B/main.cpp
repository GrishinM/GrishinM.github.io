#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>
#include <list>

using namespace std;

list<int> *mas;
int *q;
int u;
ofstream ofs("cycle.out");
stack<int> a;

int  dfs(int i)
{
    switch(q[i])
    {
    case 0:
        q[i]=1;
        for(list<int>::const_iterator it=mas[i].cbegin();it!=mas[i].cend();it++)
            if(dfs(*it))
            {
                if (q[i]==0)
                {
                    while(!a.empty())
                    {
                        ofs<<a.top()<<" ";
                        a.pop();
                    }
                    exit(0);
                }
                a.push(i);
                return 1;
            }
        q[i]=0;
        return 0;
        break;
    case 1:
        q[i]=0;
        ofs<<"YES"<<endl;
        a.push(i);
        return 1;
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("cycle.in");
    int n,m,i,x,y;
    ifs>>n>>m;
    mas=new list<int>[n+1];
    for(i=0;i<m;i++)
    {
        ifs>>x>>y;
        mas[x].push_back(y);
    }
    q=new int[n+1];
    for(int j=1;j<n+1;j++)    q[j]=0;
    for(i=1;i<n+1;i++)
    {
        dfs(i);
    }
    ofs<<"NO";
    return 0;
}

