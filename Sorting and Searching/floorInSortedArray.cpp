/*Given a sorted array arr[] of size N without duplicates, and given a value x. Find the floor of x in given array. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x.*/
#include <iostream>
#include <math.h>

using namespace std;
int findFloorUsingBinarySearch(int A[],int Asize,int x)
{
    if(A[0]>x)
        return -1;
    if(A[Asize-1]<x)
        return Asize-1;
    int mid,start=0,last=Asize-1;
    while(start<=last)
    {
        mid=(start+last)/2;
        if(A[mid]==x)
            return mid;
        if(A[mid]<x)
            start=mid+1;
        else
            last=mid-1;
    }
    return mid;
}
int findFloor(int A[],int Asize,int x)
{
    int k=Asize-1;
    if(A[0]>x)
        return -1;
    for(int i=Asize-1;i>=0;i--)
    {
       // cout<<"Loop iteration "<<i<<endl;
        if(A[i]<x)
            return k;
        if(A[i]<A[k])
            k=i;    
    }   
    return k;
}
int main()
{
    int T,N,a,X;
    cin>>T;
    if(T<1 || T>100)
    {
        cerr<<"Illegal Value of T\n";
        return -1;
    }
    while(T--)
    {
        cin>>N;
        int n=0;
        int A[N];
        cin>>X;
        while(n<N)
            cin>>A[n++];
            //printArray(A,N);
        if(N<1 || N>pow(10,7))
            continue;
        /*if(X<0 || X>A[n-1])
        {    cout<<-1<<endl;
                continue;
        }*/
        cout<<findFloorUsingBinarySearch(A,N,X)<<endl;
    }
    /*1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ arr[i] ≤ 1018
0 ≤ X ≤ arr[n-1]*/
    return 0;
}