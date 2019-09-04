#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>
#include <queue>
#include <stack>
#define int long long
#define maxll 9000000000000000000

using namespace std;

pair<int, pair<int, int>>** ans;
bool *visited;
int n;

int dfs(int u, int cmin)
{
    if(u == n - 1)    return cmin;
    visited[u] = true;
    for(int k = 1; k < n; k++)
    {
        if(ans[u][k].first)
            if(!visited[k] && ans[u][k].second.first < ans[u][k].second.second)
            {
                int delta = dfs(k, min(cmin, ans[u][k].second.second - ans[u][k].second.first));
                if(delta>0)
                {
                    ans[u][k].second.first += delta;
                    ans[k][u].first = 1;
                    ans[k][u].second.first -= delta;
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
    ifstream ifs("maxflow.in");
    ofstream ofs("maxflow.out");
    int m, i, x, a=0, y, z;
    ifs >> n >> m;
    n++;
    ans = new pair<int, pair<int, int>>*[n];
    for(i = 0; i < n; i++)    ans[i] = new pair<int, pair<int, int>>[n];
    for(i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans[i][j].first = 0;
    visited = new bool[n];
    for(i = 1; i < n; i++)    visited[i] = false;
    for(i = 0; i < m; i++)
    {
        ifs >> x >> y >> z;
        ans[x][y] = make_pair(1, make_pair(0, z));
    }
    while(dfs(1, maxll) > 0)
    {
        for(i = 1; i < n; i++)    visited[i] = false;
    }
    for(int k = 1; k < n; k++)
    {
        if(ans[1][k].first)    a += ans[1][k].second.first;
    }
    ofs << a;
    return 0;
}
