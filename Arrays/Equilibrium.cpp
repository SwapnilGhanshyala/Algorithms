#include <iostream>
#include <math.h>
using namespace std;

int main() {
/*
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108*/
int T;
cin>>T;
while(T)
{
    T--;
    int N;
    cin>>N;
    int n=0,A[N];
    while(n<N)
    {
        cin>>A[n++];
    }
    if(N<1 || N>pow(10,6))
        continue;
    if(N==1)
    {
        cout<<1<<endl;
        continue;
    }
    int flag=0;
    unsigned long sum1=A[0],sum2=A[N-1];
    for(int i=1,j=N-2;i<=j;)
    {
        if((sum1==sum2))
        {
            flag=1;
            if( i==j)
            {
            cout<<i+1<<endl;
            break;}
        }
        if(sum1<sum2)
        {sum1+=A[i];
        i++;}
        else
        {sum2+=A[j];
        j--;}
        if(flag==1)
        {
            sum1+=A[i++];
            sum2+=A[j--];
            flag=0;
        }
    }
    if(flag!=1)
        cout<<-1<<endl;
    
}return 0;
}