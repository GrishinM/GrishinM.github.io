#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>
#include <stack>

using namespace std;

list<int> *mas;
list<int> *arr;
stack<int> ord;
int *component;
int *q;
int *r;
int j=0;
int col=1;
ofstream ofs("cond.out");

int  dfs1(int i)
{
    r[i]=1;
    for(list<int>::const_iterator it=mas[i].cbegin();it!=mas[i].cend();it++)    if(!q[*it])
    {
        q[*it]=1;
        dfs1(*it);
    }
    ord.push(i);
}

int  dfs2(int i)
{
    component[i]=col;
    for(list<int>::const_iterator it=arr[i].cbegin();it!=arr[i].cend();it++)    if(!component[*it])    dfs2(*it);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("cond.in");
    int n,m,i,x,y;
    ifs>>n>>m;
    mas=new list<int>[n+1];
    arr=new list<int>[n+1];
    for(i=0;i<m;i++)
    {
        ifs>>x>>y;
        mas[x].push_back(y);
        arr[y].push_back(x);
    }
    q=new int[n+1];
    r=new int[n+1];
    component=new int[n+1];
    for(i=1;i<n+1;i++)    q[i]=0;
    for(i=1;i<n+1;i++)    component[i]=0;
    for(i=1;i<n+1;i++)    if(!q[i])
    {
        q[i]=1;
        dfs1(i);
    }
    while(!ord.empty())    if(!component[ord.top()])
                           {
                               dfs2(ord.top());
                               ord.pop();
                               col++;
                           }
                           else ord.pop();
    ofs<<col-1<<endl;
    for(int i=1;i<n+1;i++)    ofs<<component[i]<<" ";
    return 0;
}
