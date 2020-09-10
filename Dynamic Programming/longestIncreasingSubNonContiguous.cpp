#include <iostream>
using namespace std;
int longestIncreasingSubsequence(int A[],int N)
{
    int L[N],start[N],end[N];
    for(int i=0;i<N;i++)
    {
        L[i]=1;
        start[i]=i;
        end[i]=i;
    }
    for(int j=1;j<N;j++)
    {
        for(int i=0;i<j;i++)
        {
            if(A[i]<A[j] && L[i]+1>L[j])
            {
                L[j]=L[i]+1;
                start[j]=start[i];
                end[j]=j;
            }
        }
    }
    int max=0;
    for(int i=1;i<N;i++)
    {
        if(L[max]<L[i])
            max=i; 
    }
    cout<<"Range is: "<<start[max]<<" "<<end[max]<<endl;
    return L[max];
}
int main() {
    int T,N,c;
    cin>>T;
    while(T>=1)
    {
        T--;
        cin>>N;
        int n=0,A[N];
        if(N<1)
            continue;
        while(n<N)
        {
            cin>>A[n++];
        }
        if(N>1000)
            continue;
        cout<<longestIncreasingSubsequence(A,N)<<endl;
    }
/*1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 300*/	return 0;
}