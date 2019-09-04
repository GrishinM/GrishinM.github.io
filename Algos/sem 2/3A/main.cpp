#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <list>

using namespace std;

int *mas;
int *q;
int *r;
int j = 0;
ofstream ofs("output.txt");

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("input.txt");
    int n, m, i, x, y;
    ifs >> n >> m;
    mas = new int[n + 1];
    for(i = 1; i < n + 1; i++)    mas[i] = 0;
    for(i = 0; i < m; i++)
    {
        ifs >> x >> y;
        mas[x] += 1;
        mas[y] += 1;
    }
    for(i = 1; i < n + 1; i++)    ofs << mas[i] << " ";
    return 0;
}
