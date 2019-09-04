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

struct reb
{
    int a;
    int b;
    int w;
};

int *d;
int *p;
int *q;
int *a;
list<reb> rebs;
vector<pair<int, int>> *mas;

dfs(int i)
{
    a[i] = 1;
    for(auto it = mas[i].begin(); it != mas[i].end(); it++)
    {
        if(q[i])    q[it -> first] = 1;
        if(!a[it -> first])    dfs(it -> first);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("path.in");
    ofstream ofs("path.out");
    int n, m, i, s;
    ifs >> n >> m >> s;
    reb b;
    n++;
    mas = new vector<pair<int, int>>[n];
    for(i = 0; i < m; i++)
    {
        ifs >> b.a >> b.b >> b.w;
        rebs.push_back(b);
        mas[b.a].push_back(make_pair(b.b, b.w));
    }
    d = new int[n];
    p = new int[n];
    q = new int[n];
    a = new int[n];
    for(i = 1; i < n; i++)
    {
        d[i] = maxll;
        q[i] = 0;
    }
    d[s] = 0;
    for(i = 0; i < n - 2; i++)
        for(auto k = rebs.begin(); k != rebs.end(); k++)
            if(d[k -> b] > d[k -> a] + k -> w && d[k -> a] != maxll)
                d[k -> b] = d[k -> a] + k -> w;
    for(i = 1; i < n; i++)    p[i] = d[i];
    for(auto k = rebs.begin(); k != rebs.end(); k++)
            if(p[k -> b] > p[k -> a] + k -> w && p[k -> a] != maxll)
                p[k -> b] = p[k -> a] + k -> w;
    for(i = 1; i < n; i++)
    {
        if(p[i] < d[i])    q[i] = 1;
    }
    for(i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)    a[j] = 0;
        dfs(s);
    }
    for(i = 1; i < n; i++)
    {
        if(q[i] || p[i] < -5000000000000000000)    ofs << "-" << endl;
        else    if(p[i] == maxll)    ofs << "*" << endl;
                else    ofs << d[i] << endl;
    }
    return 0;
}
