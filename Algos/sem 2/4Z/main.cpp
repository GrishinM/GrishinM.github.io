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

int **d;
list<reb> rebs;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, i, s, k;
    cin >> n >> m >> k >> s;
    reb b;
    n++;
    d = new int*[k + 1];
    for(i = 0; i < k + 1; i++)
        d[i] = new int[n];
    for(i = 0; i < m; i++)
    {
        cin >> b.a >> b.b >> b.w;
        rebs.push_back(b);
    }
    for(i = 1; i < n; i++)    d[0][i] = maxll;
    for(i = 1; i < k + 1; i++)
        for(int j = 1; j < n; j++)
            d[i][j] = maxll;
    d[0][s] = 0;
    for(i = 0; i < k; i++)
        for(auto e = rebs.begin(); e != rebs.end(); e++)
            if(d[i][e -> a] != maxll)
                d[i + 1][e -> b] = min(d[i + 1][e -> b], d[i][e -> a] + e -> w);
    for(i = 1; i < n; i++)
    {
        if(d[k][i] != maxll)    cout << d[k][i] << endl;
        else cout << "-1" << endl;
    }
    return 0;
}
