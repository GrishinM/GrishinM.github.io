#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void ins(Node **head, int data)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void del(Node **head, int data)
{
    if(*head==NULL) return;
    if ((*head)->value==data)
    {
        (*head)=(*head)->next;
        return;
    }
    Node *t=(*head);
    while(t->next)
    {
        if(t->next->value==data)
        {
            t->next=t->next->next;
            return;
        }
        t = t->next;
    }
}

int ex(const Node *head, int data)
{
    while (head)
    {
        if((head->value)==data)
            return 1;
        head = head->next;
    }
    return 0;
}

int h(int data)
{
    return abs(data)%1000000;
}

int main()
{

    FILE *in=fopen("set.in", "r");
    freopen("set.out", "w", stdout);
    char s[50];
    Node **head = (Node **)malloc(sizeof(Node*) * 1000000);
    for(int t=0;t<1000000;t++) head[t]=NULL;
    int x;
    while(fscanf(in,"%s",s)!=-1)
    {
        switch(s[0])
        {
        case 'i':
            fscanf(in,"%d\n",&x);
            if(0==ex(head[h(x)],x)) ins(&head[h(x)],x);
            break;
        case 'e':
            fscanf(in,"%d\n",&x);
            if(ex(head[h(x)],x)) printf("true\n");
            else printf("false\n");
            break;
        case 'd':
            fscanf(in,"%d\n",&x);
            del(&head[h(x)],x);
            break;
        }
    }
    return 0;
}
