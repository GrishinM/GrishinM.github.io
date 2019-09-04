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
    ifstream ifs("pathsg.in");
    ofstream ofs("pathsg.out");
    int n, m, i, x, y, z, v, s;
    list<pair<int, int>> *mas;
    unsigned **d;
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
    }
    d = new unsigned*[n];
    for(i = 0; i < n; i++)    d[i] = new unsigned[n];
    U = new int[n];
    for(int j = 1; j < n; j++)
    {
        s = j;
        for(i = 1; i < n; i++)
            if(i != s)
            {
                U[i] = 0;
                d[s][i] = 4000000000;
                a.first = d[s][i];
                a.second = i;
                se.insert(a);
            }
        d[s][s] = 0;
        U[s] = 0;
        a.first = d[s][s];
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
                if(!U[it -> first] && d[s][it -> first] > d[s][v] + it -> second)
                {
                    a.first = d[s][it -> first];
                    a.second = it -> first;
                    se.erase(*se.lower_bound(a));
                    d[s][it -> first] = d[s][v] + it -> second;
                    a.first = d[s][it -> first];
                    se.insert(a);
                }
            }
        }
    }
    for(i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
            ofs << d[i][j] << " ";
        ofs << endl;
    }
    return 0;
}
