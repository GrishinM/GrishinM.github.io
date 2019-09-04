#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    int n,m,i,j,x,y;
    ifs>>n>>m;
    int **mas=new int*[n+1];
    for(i=0;i<n+1;i++)    mas[i]=new int[n+1];
    for(i=0;i<n+1;i++)
        for(j=0;j<n+1;j++)    mas[i][j]=0;
    for(i=0;i<m;i++)
    {
        ifs>>x>>y;
        mas[min(x,y)][max(x,y)]+=1;
        if(mas[min(x,y)][max(x,y)]==2)
        {
            ofs<<"YES"<<endl;
            return 0;
        }
    }
    ofs<<"NO"<<endl;
    return 0;
}
