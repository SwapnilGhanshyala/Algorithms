//#include <set>
/*Given an array A of size N, find all combination of four elements in the array whose sum is equal to a given value K. For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

The output should contain only unique quadrples  For example, if input array is {1, 1, 1, 1, 1, 1} and K = 4, then output should be only one quadrple {1, 1, 1, 1}.

Note: Print -1 if no such quadruple is found. */
//#include <bits/stdc++.h> 
#include <iostream>
#include <set>
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
int binarySearch(int A[],int start,int last,int n)
{
    while(start<=last)
    {
        int mid=(start+last)/2;
        if(A[mid]==n)
            return mid;
        if(A[mid]>n)
            last=mid-1;
        else
            start=mid+1;
    }
    return -1;
}
void printQuadForSum(int A[],int sum,int Asize)
{
    qsort(A,Asize,sizeof(int),compare);
    multiset<int> quad;
    set<multiset<int>> SetOfQuad;
    for(int i=Asize-1;i>=3;i--)
    {
        int rem1=sum-A[i];
        for(int j=i-1;j>=2;j--)
        {
            int rem2=rem1-A[j];
            for(int q=j-1;q>=1;q--)
            {
                int rem3=rem2-A[q];
                int p=binarySearch(A,0,q-1,rem3);
                if(p!=-1)
                {
                    quad.insert(A[i]);
                    quad.insert(A[j]);
                    quad.insert(A[q]);
                    quad.insert(A[p]);
                    SetOfQuad.insert(quad);
                    quad.clear();
                }
            }
        }

    }
    if(SetOfQuad.empty())
    {
        cout<<-1<<endl;
        return;
    }
    for(auto x: SetOfQuad)
    {
        for(auto it: x)
        {
            cout<<it<<" ";
        }
        cout<<"$";
    }
    cout<<endl;

}
int main()
{
    int T,N,K,a;
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
        cin >>K;
        int arr[N];
        while(n<N)
        {
            cin>>a;
            if(a<-100 || a>100)
            {
                cerr<<"Illegal Value of a\n";
                return -1;
            }
            arr[n++]=a;
        }
        if(K<-1000 || K>1000)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(N<1 || N>1000)
        {
            cout<<-1<<endl;
            continue;
        }
        printQuadForSum(arr,K,N);
    }
    /*1 <= T <= 100
1 <= N <= 1000
-1000 <= K <= 1000
-100 <= A[] <= 100*/
    return 0;
}