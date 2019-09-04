#include <iostream>
#include "fg.h"

using namespace std;

int main()
{
    rect a,b;
    vect x;
    double w;
    arr q,p;
    /*cin>>a.x>>a.y>>a.side>>a.angle>>b.x>>b.y>>b.side>>b.angle;
    cout<<"==? "<<(a==b)<<endl;
    cout<<"!=? "<<(a!=b)<<endl;
    cout<<"<? "<<(a<b)<<endl;
    cout<<">? "<<(a>b)<<endl;
    cin>>w;
    a*=w;
    cout<<a.x<<" "<<a.y<<" "<<a.side<<" "<<a.angle<<endl;
    cin>>x.x>>x.y;
    a+=x;
    cout<<a.x<<" "<<a.y<<" "<<a.side<<" "<<a.angle<<endl<<endl;*/
    cin>>q.n;
    for(int i=0;i<q.n;i++)    cin>>q.mas[i];
    cin>>p.n;
    for(int i=0;i<p.n;i++)    cin>>p.mas[i];
    cout<<"==? "<<(q==p)<<endl;
    cout<<"!=? "<<(q!=p)<<endl;
    cout<<"<? "<<(q<p)<<endl;
    cout<<">? "<<(q>p)<<endl;
    q+=p;
    for(int i=0;i<q.n;i++)    cout<<q.mas[i]<<" ";
}
