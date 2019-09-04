#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>
#include <queue>
#include <set>
#define int unsigned

using namespace std;

vector<pair<int, int>> *mas;
long long *d;
int *U;
int n, u;

struct kvaka
{
    bool operator()(pair<long long, int> const &a, pair<long long, int> const &b) const
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("pathmgep.in");
    ofstream ofs("pathmgep.out");
    int i, j, s, f, v;
    signed x;
    ifs >> n >> s >> f;
    n++;
    pair<long long, int> a;
    mas = new vector<pair<int, int>>[n];
    multiset<pair<long long, int>> :: iterator b;
    multiset<pair<long long, int>, kvaka> se;
    for(i = 1; i < n; i++)
        for(j = 1; j < n; j++)
        {
            ifs >> x;
            if(x != -1 && i != j)
            {
                a.first = j;
                a.second = x;
                mas[i].push_back(a);
            }
        }
    d = new long long[n];
    U = new int[n];
    for(i = 1; i < n; i++)
        if(i != s)
        {
            U[i] = 0;
            d[i] = 4000000000000;
            a.first = d[i];
            a.second = i;
            se.insert(a);
        }
    d[s] = 0;
    U[s] = 0;
    a.first = d[s];
    a.second = s;
    se.insert(a);
    while(!se.empty())
    {
        b = se.cbegin();
        v = b -> second;
        U[v] = 1;
        se.erase(b);
        for(auto it = mas[v].cbegin(); it != mas[v].cend(); it++)
        {
            if(!U[it -> first] && d[it -> first] > d[v] + it -> second)
            {
                a.first = d[it -> first];
                a.second = it -> first;
                se.erase(*se.lower_bound(a));
                d[it -> first] = d[v] + it -> second;
                a.first = d[it -> first];
                se.insert(a);
            }
        }
    }
    if(d[f] != 4000000000000)    ofs << d[f] << " ";
    else ofs << "-1";
    return 0;
}
