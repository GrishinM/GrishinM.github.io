#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <set>

using namespace std;

int* prefix(string s)
{
    int n = s.length();
    int k;
    int *p = new int[n];
    p[0] = 0;
    for(int i = 1; i < n; i++)
    {
        k = p[i - 1];
        while(k > 0 && s[i] != s[k])    k = p[k - 1];
        if(s[i] == s[k])    k++;
        p[i] = k;
    }
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("search1.in");
    ofstream ofs("search1.out");
    string p, t;
    ifs >> p >> t;
    int m = p.length(), n = t.length(), c = 0;
    vector<int> answer;
    int *q = prefix(p + "#" + t);
    for(int i = m + 1; i < n + m + 1; i++)
        if(q[i] == m)
        {
            answer.push_back(i - 2 * m + 1);
            c++;
        }
    ofs << c << endl;
    for(auto y = answer.begin(); y != answer.end(); y++)    ofs << *y << " ";
    return 0;
}
