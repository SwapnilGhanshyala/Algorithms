#include <iostream>
#include <math.h>
using namespace std;
//dynamic TC: O(N) SC:O(N)
int countNumOfWays1(int n)
{
    int N[n+1];
    N[1]=1;
    N[2]=2;
    for(int i=3;i<=n;i++)
        N[i]=(N[i-1]+N[i-2])%1000000007;
    return N[n];
}
//memoization TC: O(N) SC:O(N)

int countNumOfWays2(int n,int *ways)
{
    if(n==1 || n==2)
        return ways[n];
    if(ways[n-1]==0)
        ways[n]=countNumOfWays2(n-1,ways);
    else
        ways[n]=ways[n-1];
    if(ways[n-2]==0)
        ways[n]=(ways[n]+countNumOfWays2(n-2,ways))%1000000007;
    else
        ways[n]=(ways[n]+ways[n-2])%1000000007;
    return ways[n];

}
//dynamic modify TC: O(N) SC:O(1)

int countNumOfWays(int N)
{
    if(N<=2)
    return N;
    int a=1,b=2,c;
    int n=3;
    while(n<=N)
    {
        c=(a+b)%1000000007;
        a=b;b=c;n++;
    }
    return c;
}
int main() {
    /*1<=T<=105
1<=N<=105*/
    int T,N;
    cin>>T;
    while(T>0)
    {
        T--;
        cin>>N;
        if(N<1 || N>pow(10,5))
        continue;
        cout<<countNumOfWays(N)<<endl;
    }
	return 0;
}