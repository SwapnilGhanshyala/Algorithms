#include <iostream>
using namespace std;
int longestIncreasingSubsequence(int A[],int N)
{
    int currMax=1,globalMax=0,start=0,end=0,currStart=0;
    for(int i=0;i<N-1;i++)
    {
        if(A[i+1]>A[i])
        {
            if(currMax==1)
                currStart=i;
            currMax++;
        }
        else//if less tha nor equal to
        {
            if(globalMax<currMax)
            {
                start=currStart;
                end=i;
                globalMax=currMax;
            }
            currMax=1;
        }
    }
    return globalMax;
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