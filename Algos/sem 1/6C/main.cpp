#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

struct Node
{
    int key=0;
    Node *left=nullptr;
    Node *right=nullptr;
};

void ins(Node *root, int x)
{
    if(x<root->key  &&  root->left!=nullptr)   ins(root->left, x);
    if(x>root->key  &&  root->right!=nullptr)   ins(root->right, x);
    if(x<root->key  &&  root->left==nullptr)
    {
        Node *tmp=new Node;
        tmp->key=x;
        root->left=tmp;
    }
    if(x>root->key  &&  root->right==nullptr)
    {
        Node *tmp=new Node;
        tmp->key=x;
        root->right=tmp;
    }
}

bool exists(Node *root, int x)
{
   if(root==nullptr)    return false;
   if(x==root->key)    return true;
   if(x < root->key)    exists(root->left, x);
   else    exists(root->right, x);
}

Node *next(Node *root, int x)
{
   Node *current = root, *successor = nullptr;
   while(current != nullptr)
      if(current->key>x)
      {
         successor = current;
         current = current->left;
      }
      else  current = current->right;
   return successor;
}

Node *prev(Node *root, int x)
{
   Node *current = root, *successor = nullptr;
   while(current != nullptr)
      if(current->key<x)
      {
         successor = current;
         current = current->right;
      }
      else  current = current->left;
   return successor;
}

void del(Node **root, int x)
{
    if(x < (*root)->key)    del(&(*root)->left, x);
    else  if(x > (*root)->key)   del(&(*root)->right, x);
          else  if((*root)->left!=nullptr  && (*root)->right!=nullptr)
                {
                    (*root)->key=(next(*root, (*root)->key))->key;
                    //(*root)->key=(*root)->right->key;
                    del(&(*root)->right, (*root)->key);
                }
                else  if((*root)->left!=nullptr)  (*root)=(*root)->left;
                      else  (*root)=(*root)->right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream ifs("bstsimple.in");
    ofstream ofs("bstsimple.out");
    string com;
    int x,n=0;
    Node *head=nullptr;
    Node *tmp;
    while (ifs>>com>>x)
    {
        switch(com[0])
        {
        case 'i':
            if(n==0)
            {
                head=new Node;
                head->key=x;
                n=1;
            }
            else
            {
                if(!exists(head, x))
                {
                    ins(head, x);
                    n++;
                }
            }
            break;
        case 'd':
            if(exists(head, x))
            {
                del(&head,x);
                n--;
            }
            break;
        case 'e':
            ofs<<(exists(head, x)?"true":"false")<<endl;
            break;
        case 'n':
            tmp=next(head, x);
            if(tmp==nullptr)
            {
                ofs<<"none"<<endl;
            }
            else
            {
                ofs<<tmp->key<<endl;
            }
            break;
        case 'p':
            tmp=prev(head, x);
            if(tmp==nullptr)    ofs<<"none"<<endl;
            else  ofs<<tmp->key<<endl;
            break;
        }
    }
    return 0;
}
