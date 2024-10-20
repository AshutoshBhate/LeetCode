#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if(n == 1)
    {
        return x;
    }
    if(n == 0)
    {
        return 1;
    }
    return x * myPow(x, n - 1);
}

int main()
{
    int cascade = myPow(2, 2);
    cout<<cascade;

    return 0;
}
