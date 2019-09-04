#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("prefix.in");
    ofstream ofs("prefix.out");
    string p;
    ifs >> p;
    int n = p.length();
    int k;
    int a[n];
    a[0] = 0;
    for(int i = 1; i < n; i++)
    {
        k = a[i - 1];
        while(k > 0 && p[i] != p[k])    k = a[k - 1];
        if(p[i] == p[k])    k++;
        a[i] = k;
    }
    for(int i = 0; i < n; i++)    ofs << a[i] << " ";
    return 0;
}
