#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>
#include <cstdlib>

using namespace std;

ofstream ofs("spantree3.out");


struct reb
{
    int a;
    int b;
    int w;
};

reb *mas;
int *q;
long long j = 0;
int *ran;

int cmp(const void *a, const void *b)
{
    return static_cast<const reb *>(a) -> w - static_cast<const reb *>(b) -> w;
}

int dfs(int a)
{
    while(q[a] != a)    a = q[a];
    return a;
}

void MakeSet(int x)
{
    q[x] = x;
    ran[x] = 0;
}

int Find(int x)
{
    return (x == q[x] ? x : q[x] = Find(q[x]));
}

void Union(int x, int y)
{
    if ((x = Find(x)) == (y = Find(y)))    return;
    if (ran[x] <  ran[y])    q[x] = y;
    else
    {
        q[y] = x;
        if (ran[x] == ran[y])    ++ran[x];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("spantree3.in");
    int n, m, i, x, y, z, p, k;
    ifs >> n >> m;
    n++;
    mas = new reb[m];
    q = new int[n];
    ran = new int[n];
    for(i = 1; i < n; i++)    MakeSet(i);
    for(i = 0; i < m; i++)
    {
        ifs >> x >> y >> z;
        mas[i].a = x;
        mas[i].b = y;
        mas[i].w = z;
    }
    qsort(mas, m, sizeof *mas, cmp);
    for(i = 0; i < m; i++)
    {
        p = Find(mas[i].a);
        k = Find(mas[i].b);
        if(p != k)
        {
            j += mas[i].w;
            Union(mas[i].a, mas[i].b);
        }
    }
    ofs << j;
    return 0;
}
