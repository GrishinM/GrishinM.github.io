#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

struct Node
{
    int k=0;
    int l=0;
    int r=0;
};

Node* tree;

int  dfs(int i)
{
    return i==0?0:1+max(dfs(tree[i].l),dfs(tree[i].r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("height.in");
    ofstream ofs("height.out");
    int n;
    Node tmp;
    ifs>>n;
    tree=new Node[n+1];
    for(int i=1;i<=n;i++)
    {
        ifs>>tree[i].k>>tree[i].l>>tree[i].r;
    }
    ofs<<(n==0?0:dfs(1))<<endl;
    return 0;
}
