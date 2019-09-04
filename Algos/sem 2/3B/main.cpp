#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
#include <list>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

ofstream ofs("spantree.out");

struct dot
{
    int a;
    int x;
    int y;
};

float **mas;
dot *arr;
float *key;
double j = 0;
int *p;
float *Q;

int extr(int &n)
{
    float a = 1000000000;
    int k;
    for(int i = 1; i < n; i++)
        if(key[i] < a && key[i])
        {
            a = key[i];
            k = i;
        }
    return k;
}

bool emp(int &n)
{
    for(int i = 1; i < n; i++)    if(key[i])    return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("spantree.in");
    int n, i, x, y, e, u, v;
    ifs >> n;
    n++;
    mas = new float*[n];
    for(i = 0; i < n; i++)    mas[i] = new float[n];
    arr = new dot[n];
    key = new float[n];
    p = new int[n];
    Q = new float[n];
    for(i = 1; i < n; i++)
    {
        ifs >> x >> y;
        arr[i].a = i;
        arr[i].x = x;
        arr[i].y = y;
        key[i] = 1000000000;
    }
    for(i = 1; i < n - 1; i++)
        for(e = i + 1; e < n; e++)
        {
            mas[e][i] = mas[i][e] = pow(arr[i].x - arr[e].x, 2) + pow(arr[i].y - arr[e].y, 2);
        }
    while(!emp(n))
    {
        if (key[1])
        {
            key[1] = 0;
            v = 1;
        }
        else
        {
            v = extr(n);
            j += sqrt(key[v]);
            key[v] = 0;
        }
        for(u = 1; u < n; u++)
        {
            if(key[u] && u != v && key[u] > mas[v][u])
            {
                key[u] = mas[v][u];
            }
        }
    }

    ofs << setprecision(9) << j;
    return 0;
}
