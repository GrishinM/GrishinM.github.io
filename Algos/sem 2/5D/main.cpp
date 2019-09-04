#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>
#include <queue>
#include <stack>
#include <set>
#define int long long
#define maxll 9000000000000000000

using namespace std;

pair<int, pair<int, int>>** mas2;
set<int>* mas3;
bool *visited;
int n;

int dfs(int u, int cmin)
{
    if(u==n-1)    return cmin;
    visited[u]=true;
    for(auto k=mas3[u].begin();k!=mas3[u].end();k++)
    {
        //if(mas2[u][*k].first)
            if(!visited[*k] && mas2[u][*k].second.first < mas2[u][*k].second.second)
            {
                int delta=dfs(*k, min(cmin, mas2[u][*k].second.second - mas2[u][*k].second.first));
                if(delta>0)
                {
                    mas2[u][*k].second.first+=delta;
                    mas2[*k][u].first=1;
                    mas3[*k].insert(u);
                    mas2[*k][u].second.first-=delta;
                    return delta;
                }
            }
    }
    return 0;
}




signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("circulation.in");
    ofstream ofs("circulation.out");
    int m, i, x, y, z, q, u;
    ifs >> n >>m;
    if(!m)
    {
        ofs<<"NO";
        return 0;
    }
    ++(++n);
    mas2=new pair<int, pair<int, int>>*[n];
    for(i=0;i<n;i++)    mas2[i]=new pair<int, pair<int, int>>[n];
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            mas2[i][j].first=0;
            mas2[i][j].second.first=0;
            mas2[i][j].second.second=0;
        }
    visited=new bool[n];
    for(i=0;i<n;i++)    visited[i]=false;
    pair<int, pair<int, int>>** ans=new pair<int, pair<int, int>>*[m];
    /*int* sd=new int[m];
    int* df=new int[m];*/
    int* hj=new int[m];
    mas3=new set<int>[n];
    for(i = 0; i < m; i++)
    {
        ifs>>x>>y>>z>>q;
        hj[i]=z;
        //mas2[0][y]=make_pair(1, make_pair(0, z));
        mas2[0][y].first=1;
        mas2[0][y].second.second+=z;
        mas3[0].insert(y);
        mas3[x].insert(y);
        mas3[x].insert(n-1);
        //mas2[x][n-1]=make_pair(1, make_pair(0, z));
        mas2[x][n-1].first=1;
        mas2[x][n-1].second.second+=z;
        mas2[x][y]=make_pair(1, make_pair(0, q-z));
        ans[i]=&mas2[x][y];
        /*sd[i]=x;
        df[i]=y;*/
    }
    while(dfs(0, maxll)>0)
    {
        for(i=0;i<n;i++)    visited[i]=false;
    }
    /*for(i=0;i<n;i++)    if(mas2[0][i].first)*/for(auto k=mas3[0].begin();k!=mas3[0].end();k++)    if(mas2[0][*k].second.first<mas2[0][*k].second.second)
                                                {
                                                    ofs<<"NO";
                                                    return 0;
                                                }
    ofs<<"YES"<<endl;
    for(i=0;i<m;i++)
    {
        /*u=0;
        for(auto k=mas3[df[i]].begin();k!=mas3[df[i]].end();k++)    if(*k>u)    u=*k;
        ofs<<ans[i]->second.first + u<<endl;*/

        //ofs<<ans[i]->second.first + mas2[0][sd[i]].second.second<<endl;
        ofs<<ans[i]->second.first + hj[i]<<endl;
    }
    return 0;
}
