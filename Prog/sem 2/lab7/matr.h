#ifndef MATR_H_INCLUDED
#define MATR_H_INCLUDED
using namespace std;

template <class T>
class matr
{
private:
    T **mas;
    int n, m;
public:
    matr(int a, int b, T **arr)
    {
        n=a;
        m=b;
        mas=new T *[n];
        for(int i=0;i<n;i++)
            mas[i]=new T[m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mas[i][j]=arr[i][j];
    }
    void el(int i,int j)
    {
        if(i>n || i-1<0 || j>m || j-1<0)
            throw "Îøèáêà";
        cout << mas[i-1][j-1] << endl;
    }
};

#endif // MATR_H_INCLUDED
