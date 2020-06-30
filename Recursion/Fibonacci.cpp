#include <iostream>

using namespace std;

// method to generate the nth Fibonacci number.
int getNthNumber(int n,  int a, int b)
{
    if(n<=0)
        {
            cout<<"Illegal Value of n\n";
            return n;
        }
    if(n==2 )
        return b;
    return getNthNumber(--n,b,a+b);
}

int main()
{
    int N;
    cout<<"enter the nth value you want to find for series starting with 0 1 ...\n";
    cin>>N;
    cout<<getNthNumber(N,0,1)<<endl;
    return 0;
}