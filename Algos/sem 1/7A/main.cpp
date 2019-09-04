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
    int h=0;
};

Node* tree;

int  dfs(int i)
{
     return tree[i].h=(i==0?0:1+max(dfs(tree[i].l),dfs(tree[i].r)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("balance.in");
    ofstream ofs("balance.out");
    int n;
    Node tmp;
    ifs>>n;
    tree=new Node[n+1];
    for(int i=1;i<=n;i++)
    {
        ifs>>tree[i].k>>tree[i].l>>tree[i].r;
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        ofs<<tree[tree[i].r].h-tree[tree[i].l].h<<endl;
    }
    return 0;
}
