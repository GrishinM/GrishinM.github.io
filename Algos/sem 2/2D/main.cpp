#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>

using namespace std;

int **mas;
int **arr;
int *q;
int *q1;
int *r;
int *t;
int *k;
int j=0,f=0,n;
ofstream ofs("cond.out");

int dfs(int i, int a)
{
    if(!q[a])    for(int it=1;it<n;it++)
                 {
                     if(mas[a][it])
                     {
                         q[a]=1;
                         mas[i][it]=1;
                         dfs(i, it);
                     }
                 }
}

int top(int i)
{
    switch(r[q[i]])
    {
    case 0:
        r[q[i]]=1;
        for(int it=1;it<n;it++)    if(mas[i][it])    top(it);
        r[q[i]]=2;
        t[++f]=q[i];
        break;
    case 1:
        break;
    case 2:
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("cond.in");
    int m,i,x,y;
    ifs>>n>>m;
    n++;
    mas=new int*[n];
    q=new int[n];
    q1=new int[n];
    for(int h=1;h<n;h++)
    {
        mas[h]=new int[n];
        for(int w=1;w<n;w++)
            mas[h][w]=0;
    }
    for(i=0;i<m;i++)
    {
        ifs>>x>>y;
        mas[x][y]=1;
    }
    for(i=1;i<n;i++)
    {
        for(int y=1;y<n;y++)    q[y]=0;
        dfs(i, i);
    }
    for(i=1;i<n;i++)    q[i]=0;
    for(i=1;i<n;i++)
        if(!q[i])
        {
            q[i]=++j;
            for(int it=1;it<n;it++)
            {
                if(mas[i][it] && mas[it][i])    q[it]=q[i];
            }
        }
    j++;
    r=new int[j];
    for(i=1;i<j;i++)    r[i]=0;
    t=new int[j];
    for(i=1;i<j;i++)    t[i]=0;
    arr=new int*[j];
    for(int h=1;h<j;h++)
    {
        arr[h]=new int[j];
        for(int w=1;w<j;w++)
            arr[h][w]=0;
    }
    for(i=1;i<n;i++)
        for(int it=1;it<n;it++)
            if (mas[i][it])
                arr[q[i]][q[it]]=1;
    for(i=1;i<n;i++)    top(i);
    for(i=1;i<j;i++)
        for(int it=1;it<n;it++)
            if (q[it]==t[j-i])
                q1[it]=i;
    ofs<<j-1<<endl;
    for(i=1;i<n;i++)    ofs<<q1[i]<<" ";
    return 0;
}
