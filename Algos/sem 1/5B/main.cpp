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
    struct Node *next;
};

void ins(Node **head, string x, string y)
{
    Node *tmp = new Node;
    tmp->x = x;
    tmp->y = y;
    tmp->next = (*head);
    (*head) = tmp;
}
void put(Node **head, string x, string y)
{
    Node *t=(*head);
    while (t)
    {
        if((t->x)==x)
        {
            t->y=y;
            return;
        }
        t = t->next;
    }
    ins(head,x,y);
}

void del(Node **head, string x)
{
    if(*head==nullptr) return;
    if ((*head)->x==x)
    {
        (*head)=(*head)->next;
        return;
    }
    Node *t=(*head);
    while(t->next)
    {
        if(t->next->x==x)
        {
            t->next=t->next->next;
            return;
        }
        t = t->next;
    }
}

string get(const Node *head, string x)
{
    while (head)
    {
        if((head->x)==x)
            return head->y;
        head = head->next;
    }
    return "none";
}

int h(string data)
{
    int c=0;
    int n=data.length();
    for (int i=0;i<n;++i)
        c=c*10+data[i];
    return abs(c)%hashsize;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("map.in");
    ofstream ofs("map.out");
    vector<Node*> head(hashsize,nullptr);
    string com,x,y;
    while (ifs>>com>>x){
        switch(com[0])
        {
        case 'p':
            ifs>>y;
            put(&head[h(x)],x,y);
            break;
        case 'g':
            ofs<<get(head[h(x)],x)<<endl;
            break;
        case 'd':
            del(&head[h(x)],x);
            break;
        }
    }
    return 0;
}
