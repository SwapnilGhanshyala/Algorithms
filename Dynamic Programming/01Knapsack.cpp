/*You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).*/
#include <iostream>
#include <math.h>
int calculateMaxValue(int KSW,int Value[],int Weight[],int N)
{
    int KS[KSW+1][N+1];
    for(int i=0;i<=N;i++)
        KS[0][i]=0;
    for(int i=0;i<=KSW;i++)
        KS[i][0]=0;
    for(int i=1;i<=KSW;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int value=KS[i][j-1];
            int rem_weight=i-Weight[j-1];
            if(rem_weight>=0)
            {
                if(value<(KS[rem_weight][j-1]+Value[j-1]))
                    value=(KS[rem_weight][j-1]+Value[j-1]);
            }
            KS[i][j]=value;
        }
    }
    return KS[KSW][N];
}
using namespace std;
int main()
{
    /*1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
*/
int T,N,W;
cin>>T;
while(T)
{
    T--;
    cin>>N;
    cin>>W;
    int n=0,V[N],Weight[N];
    while(n<N)
        cin>>V[n++];
    n=0;
    while(n<N)
        cin>>Weight[n++];
    if(N<1 || N>1000 || W<1 ||W>1000)
        continue;
    cout<<calculateMaxValue(W,V,Weight,N)<<endl;
}
    return 0;
}