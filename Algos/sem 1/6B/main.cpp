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

bool dfs(int i,int l, int r)
{
    return (tree[i].k>l && tree[i].k<r)&&(tree[i].l?dfs(tree[i].l,l,tree[i].k):true)&&(tree[i].r?dfs(tree[i].r,tree[i].k,r):true);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("check.in");
    ofstream ofs("check.out");
    int n;
    Node tmp;
    ifs>>n;
    tree=new Node[n+1];
    for(int i=1;i<=n;i++)
    {
        ifs>>tree[i].k>>tree[i].l>>tree[i].r;
    }
    ofs<<(n?(dfs(1,-1000000000,1000000000)?"YES":"NO"):"YES")<<endl;
    return 0;
}
