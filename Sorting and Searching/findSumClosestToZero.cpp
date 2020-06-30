#include <iostream>
#include <math.h>
using namespace std;
int compare(const void *a, const void *b)
{
    const int *x=(int*) a;
    const int *y=(int*) b;
       if(*x<*y)
        return -1;
    if(*y<*x)
        return 1;
    return 0;
}
int findSumClosestToZero(int A[],int Asize)
{
    qsort(A,Asize,sizeof(int),compare);
    int minsum=A[0]+A[1];
    for(int i=0;i<Asize;i++)
    {
        if(A[i]>0 )
            break;
        for(int j=i+1;j<Asize;j++)
        {
            int sum=A[i]+A[j];
            if(abs(sum)<abs(minsum))
                minsum=sum;
            
        }
    }
    return minsum;
}
int main() {
	//code
	int T,N,a;
	cin>>T;
	if(T<0 || T>100)
	{
	    cerr<<"Illegal value of T\n";
	    return -1;
	}
	while(T--)
	{
	    cin>>N;
	    int n=0;
	    int A[N];
	    while(n<N)
	        cin>>A[n++];
	    if(N<1 || N>pow(10,3))
	        continue;
	    cout<<findSumClosestToZero(A,N)<<endl;
	}
	/*1 ≤ T ≤ 100
1 ≤ N ≤ 103
-106 ≤ a[i] ≤ 106*/
	return 0;
}