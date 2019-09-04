#ifndef FG_H_INCLUDED
#define FG_H_INCLUDED

struct vect
{
    int x;
    int y;
};

struct arr
{
    int mas[100];
    int n;
    bool operator==(const arr b) const
    {
        return (n == b.n);
    }
    bool operator!=(const arr b) const
    {
        return (n != b.n);
    }
    bool operator>(const arr b) const
    {
        return (n > b.n);
    }
    bool operator<(const arr b) const
    {
        return (n < b.n);
    }
    void operator+=(const arr b)
    {
        for(int i=n;i<n+b.n;i++)    mas[i]=b.mas[i-n];
        n+=b.n;
    }
};

struct rect
{
    int x;
    int y;
    double side;
    int angle;
    bool operator==(const rect& a) const
    {
        return (side == a.side);
    }
    bool operator!=(const rect& a) const
    {
        return (side != a.side);
    }
    bool operator>(const rect& a) const
    {
        return (side > a.side);
    }
    bool operator<(const rect& a) const
    {
        return (side < a.side);
    }
    void doubleside(int k){
        side*=k;
    }
    void operator*=(const int k)
    {
        side*=k;
    }
    void operator+=(const vect b)
    {
        x+=b.x;
        y+=b.y;
    }
};

#endif // FG_H_INCLUDED
