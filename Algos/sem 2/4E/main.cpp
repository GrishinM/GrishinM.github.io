#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>
#include <queue>
#include <stack>

using namespace std;

int *d;
int *p;
stack<int> a;

struct reb
{
    int a;
    int b;
    int w;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("negcycle.in");
    ofstream ofs("negcycle.out");
    int n, i, j, s, x;
    ifs >> n;
    reb b;
    n++;
    vector<reb> mas;
    for(i = 1; i < n; i++)
        for(j = 1; j < n; j++)
        {
            ifs >> x;
            if(x != 1000000000)
            {
                b.a = i;
                b.b = j;
                b.w = x;
                mas.push_back(b);
            }
        }
    d = new int[n];
    p = new int[n];
    for(i=1;i<n;i++)
    {
        d[i] = 1;
        p[i] = -1;

    }
    d[1] = 0;
    for(i = 0; i < n - 1; i++)
        for(auto k = mas.begin(); k != mas.end(); k++)
            if(d[k -> b] > d[k -> a] + k -> w)
            {
                d[k -> b] = d[k -> a] + k -> w;
                p[k -> b] = k -> a;
            }
    for(auto k = mas.begin(); k != mas.end(); k++)
        if(d[k -> b] > d[k -> a] + k -> w)
        {
            for(i = 0; i < n - 1; i++)
                k -> b = p[k -> b];
            k -> a = k -> b;
            while(k -> a != p[k -> b])
            {
                a.push(k -> b);
                k -> b = p[k -> b];
            }
            s = k -> b;
            a.push(k -> b);
            break;
        }
    if(!a.empty())
    {
        ofs << "YES" << endl << a.size() + 1 << endl;
        while(!a.empty())
        {
            ofs << a.top() << " ";
            a.pop();
        }
        ofs << s << " ";
    }
    else    ofs << "NO";
    return 0;
}
