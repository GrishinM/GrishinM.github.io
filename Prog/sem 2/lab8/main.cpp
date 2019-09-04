#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
using namespace std;

template <class iter, class pred>
bool all_of(iter k, iter e, pred f)
{
    for(; k != e; k++)
        if (!f(*k))    return false;
    return true;
}

template <class iter, class pred>
bool one_of(iter k, iter e, pred f)
{
    int r = 0;
    for(; k != e; k++)
        if (f(*k))    r++;
    return (r == 1 ? true : false);
}

template <class iter, class pred>
iter find_backward(iter k, iter e, pred f)
{
    e--;
    for(; e != k; e--)
        if (f(*e))    return e;
    if(f(*e))    return k;
    throw "none";
}

struct CPoint
{
    int x, y;
    CPoint(int a, int b): x(a), y(b){}
    void draw()
    {
        cout << "(" << x << ", " << y << ")" << "  ";
    }
};

int main()
{
    list<int> q{1, 2, 3, 4, 5, 6};
    cout << "list<int>: ";
    for(auto i = q.begin(); i != q.end(); i++)    cout << (*i) << " ";
    cout << endl << endl << "all_of <7?   ";
    cout << (all_of(q.begin(), q.end(), [](int x){return x < 7;}) ? "true" : "false") << endl;
    cout << "one_of =3?   ";
    cout << (one_of(q.begin(), q.end(), [](int x){return x == 3;}) ? "true" : "false") << endl;
    cout << "find_backward >7   ";
    try
    {
        auto u = find_backward(q.begin(), q.end(), [](int x){return x > 7;});
        cout << to_string(*u);
    }
    catch(const char* str)
    {
        cout << str;
    }



    CPoint a(1,1);
    CPoint b(-1, 1);
    CPoint c(1, -1);
    CPoint d(-1, -1);
    CPoint mas[4]{a, b, c, d};
    cout << endl << endl << endl << "arr of CPoint: ";
    for(auto i = 0; i != 4; i++)    mas[i].draw();
    cout << endl << endl << "all_of x>0 & y>0?   ";
    cout << (all_of(&mas[0], &mas[4], [](CPoint x){return x.x > 0 && x.y > 0;}) ? "true" : "false") << endl;
    cout << "one_of x>0 & y<0?   ";
    cout << (one_of(&mas[0], &mas[4], [](CPoint x){return x.x > 0 && x.y < 0;}) ? "true" : "false") << endl;
    cout << "find_backward x>0   ";
    try
    {
        auto s = find_backward(&mas[0], &mas[4], [](CPoint x){return x.x > 0;});
        s -> draw();
    }
    catch(const char* str)
    {
        cout << str;
    }
    cout << endl;
}
