#include <iostream>
#include <functional>
#include <vector>

using namespace std;
template<typename ValueType>
class Node: public iterator<bidirectional_iterator_tag, ValueType>
{
public:
    bool operator!=(Node const& other) const
    {
        return value!=other.value;
    }
    bool operator==(Node const& other) const
    {
        return value==other.value;
    }
    typename Node::reference operator*() const;
    ValueType& operator*()
    {
        return value;
    }
    Node& operator++()
    {
        Node *t = this;
        if (t->l)
        {
            t=t->l;
        }
        else
        {
            if (t->r)
            {
                t=t->r;
            }
            else
            {
                while (t->parent && (t->parent->l==nullptr || (*(t->parent->l)!=*t)||(t->parent->r==nullptr)))
                {
                    t=t->parent;
                }
                if (t->parent)
                {
                    *this=*(t->parent->r);
                    return *this;
                }
                *this=*(t);
                return *this;
            }
        }
        *this=*t;
        return *this;
    }
    Node& operator++(int)
    {
        auto result=*this;
        ++(*this);
        return result;
    }
    Node& operator--()
    {
        Node t = *this;
        auto x=t.value;
        auto p=t;
        ++t;
        while(t.value!=x)
        {
            p=t;
            ++t;
        }
        *this=p;
        return *this;
    }
    Node& operator--(int)
    {
        auto result=*this;
        --(*this);
        return result;
    }
    Node(ValueType value): value(value){}
    Node (Node &a):l(a.l), r(a.r), parent(a.parent), value(a.value){}
    ValueType value;
    Node* l=nullptr;
    Node* r=nullptr;
    Node* parent=nullptr;
};

template<typename ValueType>
class constNode
{
    Node<ValueType> a;
public:
    constNode(Node<ValueType> it): a(it){}
    const ValueType &operator*()
    {
        const ValueType &c = a.value;
        return c;
    }
    constNode& operator++()
    {
        ++a;
        return *this;
    }
    constNode& operator++(int)
    {
        auto result=*this;
        ++a;
        return result;
    }
    constNode& operator--()
    {
        --a;
        return *this;
    }
    constNode& operator--(int)
    {
        auto result=*this;
        --a;
        return result;
    }
    bool operator!=(constNode const& other) const
    {
        return a!=other.a;
    }
    bool operator==(constNode const& other) const
    {
        return a==other.a;
    }
};

template<class T>
class BST
{
public:
    typedef Node<T> iterator;
    typedef constNode<T> const_iterator;
    BST()
    {
        endNode=new iterator(-1000000);
        beginNode=endNode;
    }
    BST(BST& tree)
    {
        n=tree.size();
        endNode=new iterator(-1000000);
        if(!tree.empty())
        {
            endNode->r=new iterator(tree.begin().value);
            beginNode=endNode->r;
            beginNode->parent=endNode;
            dfscopy(tree.begin(), beginNode);
        }
        else    beginNode=endNode;
    }
    BST& operator=(BST& tree)
    {
        n=tree.size();
        endNode=new iterator(-1000000);
        if(!tree.empty())
        {
            endNode->r=new iterator(tree.begin().value);
            beginNode=endNode->r;
            beginNode->parent=endNode;
            dfscopy(tree.begin(), beginNode);
        }
        else    beginNode=endNode;
    }
    template<class InputIt>
    void assign(InputIt first, InputIt last)
    {
        BST<T> *a=new BST<T>;
        for(auto b=first; b!=last; b++)    a->insert(*b);
        beginNode=a->beginNode;
        endNode=a->endNode;
        n=a->size();
    }
    iterator &begin()
    {
        return *beginNode;
    }
    const_iterator &cbegin()
    {
        const_iterator b(*beginNode);
        return b;
    }
    iterator &end()
    {
        return *endNode;
    }
    const_iterator &cend()
    {
        const_iterator b(*endNode);
        return b;
    }
    iterator &insert(const T &value)
    {
        if(beginNode==endNode)
        {
            n=1;
            endNode->r=new iterator(value);
            beginNode=endNode->r;
            beginNode->parent=endNode;
            return *beginNode;
        }
        iterator** qw=&beginNode, *last = endNode;
        while((*qw))
        {
            if((*qw)->value > value)
            {
                last=*qw;
                qw=&((*qw)->l);
            }
            else    if((*qw)->value < value)
                    {
                        last=*qw;
                        qw=&((*qw)->r);
                    }
                    else    return  **qw;
        }
        (*qw)=new iterator(value);
        (*qw)->parent=last;
        n++;
        return **qw;
    }
    iterator &remove(const T &value)
    {
        iterator &t = find(value);
        if(t==end())    return t;
        n--;
        return remove(&t);
    }
    iterator &find(const T &value)
    {
        iterator* qw=beginNode;
        while(qw)
        {
            if(qw->value > value)    qw=qw->l;
            else    if(qw->value < value)    qw=qw->r;
                    else    return  *qw;
        }
        return end();
    }
    const_iterator &find(const T &value) const
    {
        iterator a=find(value);
        const_iterator b(a);
        return b;
    }
    bool empty() const
    {
        return !n;
    }
    void print()
    {
        if (beginNode!=endNode)
        {
            cout<<beginNode->value<<" ";
            print(beginNode->l);
            print(beginNode->r);
        }
        cout<<endl;
    }
    size_t size() const
    {
        return n;
    }
private:
    iterator* beginNode;
    iterator* endNode;
    int n=0;
    iterator &remove(iterator *t)
    {
        if(t->r && t->l)
        {
            t->value=t->r->value;
            remove(t->r);
        }
        else    if(t->l)
                {
                    t->l->parent=t->parent;
                    if(t->parent->l && *(t->parent->l)==*t)    t->parent->l=t->l;
                    else    t->parent->r=t->l;
                }
                else    if(t->r)
                        {
                            t->r->parent=t->parent;
                            if(t->parent->l && *(t->parent->l)==*t)    t->parent->l=t->r;
                            else    t->parent->r=t->r;
                        }
                        else
                        {
                            if (t==beginNode)
                            {
                                endNode->r=nullptr;
                                beginNode=endNode;
                            }
                            else
                            {
                                if(t->parent->l && *(t->parent->l)==*t)    t->parent->l=nullptr;
                                else    t->parent->r=nullptr;
                            }

                        }
        if(beginNode!=endNode)
        {
            *beginNode=*endNode->r;
        }
        return end();
    }
    void print(iterator *t)
    {
        if(t)
        {
            cout<<t->value<<"("<<t->parent->value<<") ";
            print(t->l);
            print(t->r);
        }

    }
    void dfscopy(iterator a, iterator *newa)
    {
        if(a.l)
        {
            newa->l=new iterator(a.l->value);
            newa->l->parent=newa;
            dfscopy(*a.l, newa->l);
        }
        if(a.r)
        {
            newa->r=new iterator(a.r->value);
            newa->r->parent=newa;
            dfscopy(*a.r, newa->r);
        }
    }
};

int main()
{
    BST<int> a;
    a.insert(10);
    a.print();
    a.insert(15);
    a.print();


    BST<int>::const_iterator e=a.cbegin();
}
