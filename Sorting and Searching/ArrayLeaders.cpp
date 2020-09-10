#include <iostream>
#include <math.h>
using namespace std;

int main() {
/*1 <= T <= 100
1 <= N <= 107
0 <= Ai <= 107*/
int T;
cin>>T;
while(T)
{
    T--;
    int N,n=0;
    cin>>N;
    int A[N],M[N];
    while(n<N)
    {
        M[n]=0;
        cin>>A[n++];
    }
    if(N<1 || N>pow(10,7))
        continue;
    M[N-1]=1;
    int lastLeader=n-1;
    for(int i=N-2;i>=0;i--)
    {
        if(A[i]>=A[lastLeader])
        {
            lastLeader=i;
            M[i]=1;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(M[i]==1)
            cout<<A[i]<<" ";
    }
    cout<<endl;
}return 0;
}