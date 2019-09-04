#include <iostream>
#include <fstream>
#include <list>
#include <set>

using namespace std;

struct kvaka
{
    bool operator()(pair<unsigned, int> const &a, pair<unsigned, int> const &b) const
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("pathbgep.in");
    ofstream ofs("pathbgep.out");
    int n, m, i, x, y, z, v;
    list<pair<int, int>> *mas;
    unsigned *d;
    int *U;
    pair<int, int> a;
    ifs >> n >> m;
    n++;
    multiset<pair<unsigned, int>> :: iterator b;
    multiset<pair<unsigned, int>, kvaka> se;
    mas = new list<pair<int, int>>[n];
    for(i = 0; i < m; i++)
    {
        ifs >> x >> y >> z;
        a.first = y;
        a.second = z;
        mas[x].push_back(a);
        a.first = x;
        mas[y].push_back(a);
    }
    d = new unsigned[n];
    U = new int[n];
    d[1] = 0;
    U[1] = 0;
    se.insert(make_pair(0, 1));
    for(i = 2; i < n; i++)
    {
        U[i] = 0;
        d[i] = 4000000000;
        se.insert(make_pair(d[i], i));
    }
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
                se.erase(*se.lower_bound(make_pair(d[it -> first], it -> first)));
                d[it -> first] = d[v] + it -> second;
                se.insert(make_pair(d[it -> first], it -> first));
            }
        }
    }
    for(i = 1; i < n; i++)    ofs << d[i] << " ";
    return 0;
}
