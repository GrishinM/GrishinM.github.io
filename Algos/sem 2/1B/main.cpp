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
    int n,i,j;
    ifs>>n;
    int **mas=new int*[n];
    for(i=0;i<n;i++)    mas[i]=new int[n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)    ifs>>mas[i][j];
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        {
            if(i==j && mas[i][j]==1)
            {
                ofs<<"NO"<<endl;
                return 0;
            }
            if(mas[i][j]!=mas[j][i])
            {
                ofs<<"NO"<<endl;
                return 0;
            }
        }
    ofs<<"YES"<<endl;
    return 0;
}
