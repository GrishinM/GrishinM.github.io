#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
int hashsize=50000;
using namespace std;
struct Node
{
    string x;
    string y;
    Node *prevel=nullptr;
    Node *nextel=nullptr;
    Node *next=nullptr;
};

Node* ins(Node **head, string x, string y)
{
    Node *tmp = new Node;
    tmp->x = x;
    tmp->y = y;
    tmp->next = (*head);
    (*head) = tmp;
    return tmp;
}
Node* put(Node **head, string x, string y)
{
    Node *t=(*head);
    while (t)
    {
        if((t->x)==x)
        {
            t->y=y;
            return nullptr;
        }
        t = t->next;
    }
    return ins(head,x,y);
}
void d(Node *t){
    if (t->nextel!=nullptr){
        t->nextel->prevel=t->prevel;
    }
    if (t->prevel!=nullptr){
        t->prevel->nextel=t->nextel;
    }
}
void del(Node **head, string x)
{
    if(*head==nullptr) return;
    if ((*head)->x==x)
    {
        d(*head);
        (*head)=(*head)->next;
        return;
    }
    Node *t=(*head);
    while(t->next)
    {
        if(t->next->x==x)
        {
            d(t->next);
            t->next=t->next->next;
            return;
        }
        t = t->next;
    }
}

Node *get(Node *t, string x)
{
    while (t)
    {
        if((t->x)==x)
            return t;
        t = t->next;
    }
    return nullptr;
}

int h(string data)
{
    int c=0;
    int n=data.length();
    for (int i=0;i<n;++i)
        c=c*10+data[i];
    return abs(c)%hashsize;
}

Node *prev(Node **head, string x)
{
    Node *t=(*head);
    while (t)
    {
        if((t->x)==x)
        {
            break;
        }
        t = t->next;
    }
    return t->prevel;
}

Node *next(Node **head, string x)
{
    Node *t=(*head);
    while (t)
    {
        if((t->x)==x)
        {
            break;
        }
        t = t->next;
    }
    return t->nextel;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("linkedmap.in");
    ofstream ofs("linkedmap.out");
    vector<Node*> head(hashsize,nullptr);
    string com,x,y;
    Node *pred=nullptr,*tmp;
    while (ifs>>com>>x){
        switch(com[0])
        {
        case 'p':
            if(com[1]=='u')
            {
                ifs>>y;
                tmp=put(&head[h(x)],x,y);
                if (tmp!=nullptr)
                {
                    if (pred!=nullptr)
                    {
                        pred->nextel=tmp;
                    }
                    tmp->prevel=pred;
                    pred=tmp;
                }
            }
            else
            {
                if(get(head[h(x)],x)==nullptr)
                {
                    ofs<<"none"<<endl;
                }
                else
                {
                    tmp=get(head[h(x)],x)->prevel;
                    ofs<<((tmp==nullptr)?"none":tmp->y)<<endl;
                }
            }
            break;
        case 'g':
            tmp=get(head[h(x)],x);
            ofs<<((tmp==nullptr)?"none":tmp->y)<<endl;
            break;
        case 'd':
            if ((pred!=nullptr)&&(pred->x==x))
            {
                pred=nullptr;
            }
            del(&head[h(x)],x);
            break;
        case 'n':
            if(get(head[h(x)],x)==nullptr)
            {
                ofs<<"none"<<endl;
            }
            else
            {
                tmp=get(head[h(x)],x)->nextel;
                ofs<<((tmp==nullptr)?"none":tmp->y)<<endl;
            }
            break;
        }
    }
    return 0;
}
