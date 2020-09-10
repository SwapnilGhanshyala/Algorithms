#include <iostream>
#include <math.h>
using namespace std;
long KadaneAlgorithm(int A[],int N)
{
    long start[N],end[N];
    long maxcurr,maxglobal;maxcurr=maxglobal=A[0];
    for(int i=1;i<N;i++)
    {
        if(maxcurr+A[i]>A[i])
            maxcurr=maxcurr+A[i];
        else
            maxcurr=A[i];
        if(maxglobal<maxcurr)
            maxglobal=maxcurr;
    }
    return maxglobal;
}
//first Attempt
long findMaxSumofSubSequence(int A[],int N,int neg_inf)
{
    long K[N][N],mark[N][N];
    for(int i=0;i<N;i++)
        {K[i][i]=A[i];
        mark[i][i]=neg_inf;
        }
    
    int m;long sum;
    for(int i=N-2;i>=0;i--)
    {
        for(int j=i+1;j<N;j++)
        {
          //calculate K[i][j]
          sum=K[i][j-1];
          mark[i][j]=i;
          for(m=i+1;m<=j-1;m++)
          {
              if(K[m][j-1]>sum)
              {
                  sum=K[m][j-1];
                  mark[i][j]=m;
              }
          }
          K[i][j]=sum+A[j];
        }
    }
    sum=K[0][0];
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            if(K[i][j]>sum)
            sum=K[i][j];
        }
    }
    
    return sum;
}
int main() {
	//code
	int T,N;
	cin>>T;
	while(T>0)
	{
	    T--;
	    cin>>N;
	    if(N<1)
	    continue;
	    int n=0,c;
	    int A[N];
	    while(n<N)
	    {
	        cin>>c;
	        if(c>pow(10,7) || c<-(pow(10,7)))
	        {
	            continue;
	        }
	        A[n]=c;
	        n++;
	    }
	    if(N>pow(10,6))
	    continue;
	    cout<<findMaxSumofSubSequence(A,N,(-107*N))<<endl;
        cout<<KadaneAlgorithm(A,N)<<endl;
	}
	/*1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107*/
	return 0;
}