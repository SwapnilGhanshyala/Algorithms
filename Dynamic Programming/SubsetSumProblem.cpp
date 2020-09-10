
/*Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.*/
#include <iostream>
#include <math.h>

using namespace std;
int compare(const void *a,const void *b)
{
    const int* x = (int*) a;
	const int* y = (int*) b;
	
	if(*x>*y)
        return 1;
    if(*y>*x)
        return -1;
    return 0;
}
template <typename T>
void printArray(T A[],int col)
{
        for(int j=0;j<col;j++)
            cout<<A[j]<<" ";
    cout<<endl;
}
string subsetSum2(int A[],int N)
{
    int sum=0;
    for(int i=0;i<N;i++)
        sum+=A[i];
    if(sum%2==1)
        return "NO";
    sum=sum/2;
    //sort the array
    qsort(A,N,sizeof(int),compare);
    printArray(A,N);
    bool SS[N+1][sum+1];
    //using no elements non of the sums are possible
    for(int j=0;j<=sum;j++)
        SS[0][j]=false;
    //SS[0][0]=true;
    //for all sums j that are less than the smallest element 0 set S[i][j]=false
    for(int j=A[0]-1;j>=0;j--)
    {
        for(int i=1;i<=N;i++)
            SS[i][j]=false;
    }
    //for all SS[i][A[i-1]=true
    for(int i=1;i<=N;i++)
    {
        for(int k=i;k<=N;k++)
        {
           SS[k][A[i-1]]=true; 
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=A[i-1]+1;j<=sum;j++)
        {
            SS[i][j]=SS[i-1][j-A[i-1]];
        }
    }
    /*for(int i=0;i<=N;i++)
    {    for(int j=0;j<=sum;j++)
            cout<<SS[i][j]<<' ';
        cout<<endl;
    }*/
    if(SS[N][sum])
    return "YES";
    else
    return "NO";
}
bool isSubsetSum(int set[], int n, int sum) 
{ 
    // Base Cases 
    if (sum == 0) 
        return true; 
    if (n == 0 && sum != 0) 
        return false; 
  
    // If last element is greater than sum, 
    // then ignore it 
    if (set[n - 1] > sum) 
        return isSubsetSum(set, n - 1, sum); 
  
    /* else, check if sum can be obtained by any  
of the following: 
      (a) including the last element 
      (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum) 
           || isSubsetSum(set, n - 1, sum - set[n - 1]); 
} 
 
string subsetSum(int A[],int N)
{
    int sum=0;
    for(int i=0;i<N;i++)
        sum+=A[i];
    if(sum%2==1)
        return "NO: odd sum";
    sum=sum/2;
    cout<<"sum is "<<sum<<endl;

    //sort the array
    qsort(A,N,sizeof(int),compare);
        printArray(A,N);

    bool SS1[sum+1],SS2[sum+1];
    //Initial round considering only 1st element
    for(int i=0;i<=sum;i++)
    {
        SS1[i]=false;
    }
    SS1[A[0]]=true;
    for(int i=2;i<=N;i++)//starting 2nd elemnt to Nth element
    {     
        for(int j=0;j<=sum;j++)
        {
            if(j<A[i-1])
            {   
                continue;
            }
            if(j==A[i-1])
            {
                SS1[j]=true;
                continue;
            }
            SS1[j]=SS1[j-A[i-1]] || SS1[j];
        }
        //printArray(SS1,sum+1);
        if(SS1[sum])
            return "YES";
    }
/*
if(isSubsetSum(A,N,sum)==true)
    return "YES";
else*/
    return "NO";
}
int main()
{
    int T,N,c;
    cin>>T;
    while(T>0)
    {
        T--;
        cin>>N;
        if(N<1)
        continue;
        int n=0,A[N];
        while(n<N)
        {
            cin>>A[n++];
        }
        if(N>100)
            continue;
        cout<<subsetSum2(A,N)<<endl;
    /*1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000*/
    }
    return 0;
}