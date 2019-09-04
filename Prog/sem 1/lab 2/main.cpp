#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float  z1,z2,a;
    scanf("%f", &a);
    z1=2*sin(3*M_PI-2*a)*sin(3*M_PI-2*a)*cos(5*M_PI+2*a)*cos(5*M_PI+2*a);
    z2=0.25-0.25*sin(2.5*M_PI-8*a);
    printf("%f\n%f", z1,z2);
}
