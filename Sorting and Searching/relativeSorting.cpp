/*Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.
Note: Expected time complexity is O(N log(N)).*/

#include <iostream>
#include <unordered_map>
#include <math.h>

using namespace std;
int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}
void printRelativelySortedArray(int A[],int B[],int N,int M)
{
    unordered_map<int, int> bumap;
    for(int i=0;i<M;i++)
        bumap[B[i]]=0;
    int i,j;
    for( i=0,j=N;i<j;)
    {
        if(bumap.find(A[i])==bumap.end())
        {
            j--;
            int t=A[i];
            A[i]=A[j];
            A[j]=t;
        } 
        else
        {
            bumap[A[i]]++;
            i++;
        }           
    }
    qsort(&A[j],N-j,sizeof(int),compare);
    for(i=0;i<M;i++)
    {
        int count=bumap[B[i]];
        while(count>0)
            {
                cout<<B[i]<<" ";
                count--;
            }
    }
    for(;j<N;j++)
    {
        cout<<A[j]<<" ";
    }
    cout<<endl;
}
int main()
{
    /*Input:
First line of input contains number of testcases. 
For each testcase, first line of input contains length of arrays N and M 
and next two line contains N and M elements respectively.*/
    int T,N,M,a,b;
    cin>>T;
    while(T>0)
    {
        T--;
        cin>>N;
        cin>>M;
        int n=0,m=0;
        int A[N],B[M];
        while(n<N)
        {
            cin>>a;
            A[n]=a;
            n++;
        }
        while(m<M)
        {
            cin>>b;
            B[m]=b;
            m++;
        }
        if(N<1 || M<1 || N>pow(10,6) || M>pow(10,6))
            continue;
        printRelativelySortedArray(A,B,N,M);
    }
    return 0;
}