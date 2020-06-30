// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void printArray(int A[],int Asize)
{
    for(int i=0;i<Asize;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
	}
    return 0;
}// } Driver Code Ends


/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/int compare(const void *a,const void *b)
{
    const int* x=(int*) a;
    const int* y=(int*) b;
    if(*x<*y)
        return -1;
    if(*y<*x)
        return 1;
    return 0;
}
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
int BinarySearch(int A[],int n,int start,int end)
{
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(A[mid]==n)
            return mid;
        if(A[mid]<n)
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}
bool ifsumexits(int A[],int sum,int start,int Asize)
{
    for(int i=start;i<Asize;i++)
    {
        int e=sum-A[i];
        int p;
        if(e>=A[i])
        {    p=BinarySearch(A,e,i+1,Asize-1);
            cout<<"p: "<<p<<" for "<<e<<endl;;
        }
        else
            continue;
        if(p!=-1)
            return true;
    }
    return false;
}
bool findTriplets(int arr[], int n)
{ 
    qsort(arr,n,sizeof(int),compare);
    printArray(arr,n);
    for(int i=0;i<n-2;i++)
    {   if(arr[i]<=0)
        {    if(ifsumexits(arr,0-(arr[i]),i+1,n))
                return true;
        }
        else
             break;
    }
    return false;
}