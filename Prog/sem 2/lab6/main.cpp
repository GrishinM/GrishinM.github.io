#include <iostream>
#include <math.h>

using namespace std;

template <class T, class Y>
void st(const T &a, const Y &b)
{
    T r = pow(a, b);
    cout << r;
}

int main()
{
    double a;
    int b;
    cin >> a >> b;
    st(a, b);
}
