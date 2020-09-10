#include <iostream>
#include <math.h>
using namespace std;
int minNumJumps(int A[],int N)
{
    int S[N];
    S[N-1]=0;
    S[0]=-1;
    for(int i=N-2;i>=0;i--)
    {
        if(A[i]==0)
         {   S[i]=-1;
         continue;
         }
        if(i+A[i]>=N-1)
            S[i]=1;
        else
        {
            int min=S[i+1];
            //cout<<"For "<<i<<" working with minimum "<<min<<endl;
            for(int j=2;j<=A[i];j++)
            {
                if(S[i+j]<min && S[i+j]>0)
                {    min=S[i+j];
                continue;}
                if(min<0 && S[i+j]>0)
                {
                    min=S[i+j];
                }
            }
            if(min==-1)
                S[i]=-1;
            else
                S[i]=min+1;
        }
    }
    return S[0];
}
int main() {
    int T,N,c;
    cin>>T;
    while(T>0)
    {
        T--;
        cin>>N;
        int n=0,A[N];
        while(n<N)
        {
            cin>>A[n++];
        }
        if(N<1 || N>pow(10,7))
            continue;
        cout<<minNumJumps(A,N)<<endl;
       /*1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107*/ 
    }
    
	return 0;
}