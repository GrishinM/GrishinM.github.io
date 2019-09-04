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
    int c=0;
};

Node* tree;
int  head=1;
ofstream ofs("rotation.out");

int  dfs(int i)
{
    return tree[i].h=(i==0?0:1+max(dfs(tree[i].l),dfs(tree[i].r)));
}
int dfsc(int i)
{
    return tree[i].c=(i==0?0:1+dfsc(tree[i].l)+dfsc(tree[i].r));
}
void  rotateLeft(int a)
{
    int  b=tree[a].r;
    head=tree[a].r;
    tree[a].r=tree[b].l;
    tree[b].l=a;
}

void  rotateRight(int a)
{
    int  b=tree[a].l;
    tree[a].l=tree[b].r;
    tree[b].r=a;
}

void  bigRotateLeft(int a)
{
    int  c=tree[tree[a].r].l;
    rotateRight(tree[a].r);
    tree[a].r=c;
    rotateLeft(a);
}
void print(int i,int s)
{
    if (i==0) return;
    s++;
    ofs<<tree[i].k<<" "<<(tree[i].l==0?0:s)<<" "<<(tree[i].r==0?0:s+tree[tree[i].l].c)<<endl;
    print(tree[i].l,s);
    s+=tree[tree[i].l].c;
    print(tree[i].r,s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("rotation.in");
    int n;
    Node tmp;
    ifs>>n;
    tree=new Node[n+1];
    for(int i=1;i<=n;i++)
    {
        ifs>>tree[i].k>>tree[i].l>>tree[i].r;
    }
    dfs(1);
    if((tree[tree[tree[1].r].r].h-tree[tree[tree[1].r].l].h)==-1)
    {
        bigRotateLeft(1);
    }
    else
    {
        rotateLeft(1);
    }
    ofs<<n<<endl;
    dfsc(head);
    print(head,1);
    return 0;
}
