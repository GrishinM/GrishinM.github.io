#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>

using namespace std;

int **mas;
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
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    int m,i,y;
    char x;
    ifs>>n>>m;
    mas=new int*[n];
    for(i=0;i<n;i++)    mas[i]=new int[m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            ifs<<x;
            switch(x)
            {
            case '#':
                mas[i][j]=0;
            case '.':
                mas[i][j]=1;
            case 'S':
                mas[i][j]=2;
                is=i;
                js=j;
            case 'T':
                mas[i][j]=3;
                ie=i;
                je=j;
            }
        }



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
