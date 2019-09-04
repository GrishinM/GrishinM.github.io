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
int  head=1,m;
ofstream ofs("deletion.out");

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
    tree[a].r=tree[b].l;
    tree[b].l=a;
    if(tree[tree[b].l].k==tree[head].k)
        head=b;
}

void  rotateRight(int a)
{
    int  b=tree[a].l;
    tree[a].l=tree[b].r;
    tree[b].r=a;
    if(tree[tree[b].r].k==tree[head].k)
        head=b;
}

void  bigRotateLeft(int a)
{
    int  c=tree[tree[a].r].l;
    rotateRight(tree[a].r);
    tree[a].r=c;
    rotateLeft(a);
}

void  bigRotateRight(int a)
{
    int  c=tree[tree[a].l].r;
    rotateLeft(tree[a].l);
    tree[a].l=c;
    rotateRight(a);
}

void print(int i,int s)
{
    if (i==0)
        return;
    s++;
    ofs<<tree[i].k<<" "<<(tree[i].l==0?0:s)<<" "<<(tree[i].r==0?0:s+tree[tree[i].l].c)<<endl;
    print(tree[i].l,s);
    s+=tree[tree[i].l].c;
    print(tree[i].r,s);
}

int  diff(int i)
{
    return  tree[tree[i].l].h-tree[tree[i].r].h;
}

void  per(int i, int last, int p)
{
    dfs(i);
    if(diff(i)==-2 && (diff(tree[i].r)==-1 || diff(tree[i].r)==0))
    {
        if(last!=i)
            if(p)
                tree[last].l=tree[i].r;
            else
                tree[last].r=tree[i].r;
        rotateLeft(i);
    }
    else    if(diff(i)==2 && (diff(tree[i].l)==1 || diff(tree[i].l)==0))
    {
        if(last!=i)
            if(p)
                tree[last].r=tree[i].l;
            else
                tree[last].l=tree[i].l;
        rotateRight(i);
    }
    else    if(diff(i)==-2 && diff(tree[i].r)==1 && (diff(tree[tree[i].r].l)==-1 || diff(tree[tree[i].r].l)==0 || diff(tree[tree[i].r].l)==1))
    {
        if(last!=i)
            if(p)
                tree[last].l=tree[tree[i].r].l;
            else
                tree[last].r=tree[tree[i].r].l;
        bigRotateLeft(i);
    }
    else    if(diff(i)==2 && diff(tree[i].l)==-1 && (diff(tree[tree[i].l].r)==-1 || diff(tree[tree[i].l].r)==0 || diff(tree[tree[i].l].r)==1))
    {
        if(last!=i)
            if(p)
                tree[last].r=tree[tree[i].l].r;
            else
                tree[last].l=tree[tree[i].l].r;
        bigRotateRight(i);
    }
}

int  prev(int i, int x)
{
    int  current = i, successor = 0;
    while(current != 0)
        if(tree[current].k<x)
        {
            successor = current;
            current = tree[current].r;
        }
        else
            current = tree[current].l;
    return successor;
}

void del(int i,int x,int last, int q)
{
    if(x < tree[i].k)
    {
        del(tree[i].l,x,i,1);
        per(i, last, m=(tree[last].k<tree[i].k?0:1));
    }
    else  if(x > tree[i].k)
    {
        del(tree[i].r,x,i,0);
        per(i, last, m=(tree[last].k<tree[i].k?1:0));
    }
    else  if(tree[i].l!=0 && tree[i].r!=0)
    {
        tree[i].k=tree[prev(i, tree[i].k)].k;
        del(tree[i].l, tree[i].k,i,1);
        per(i, last, m=(tree[last].k<tree[i].k?0:1));
    }
    else  if(tree[i].l!=0)
    {
        tree[i].k=tree[tree[i].l].k;
        tree[i].r=tree[tree[i].l].r;
        tree[i].l=tree[tree[i].l].l;
    }
    else  if(tree[i].r!=0)
    {
        tree[i].k=tree[tree[i].r].k;
        tree[i].l=tree[tree[i].r].l;
        tree[i].r=tree[tree[i].r].r;
    }
    else
    {
        if(q)  tree[last].l=0;
        else  tree[last].r=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("deletion.in");
    int n,x;
    Node tmp;
    ifs>>n;
    tree=new Node[n+2];
    for(int i=1; i<=n; i++)
    {
        ifs>>tree[i].k>>tree[i].l>>tree[i].r;
    }
    ifs>>x;
    if(n==1)
    {
        ofs<<0<<endl;
        return 0;
    }
    dfs(1);
    del(1,x,1,0);
    ofs<<n-1<<endl;
    dfsc(head);
    print(head,1);
    return 0;
}
