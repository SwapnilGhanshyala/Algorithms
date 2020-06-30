#include <unordered_map>
#include <iostream>
#include <math.h>
using namespace std; 
int compare(long A[], long B[],int size)
{
    unordered_map<long, int> umap; 
    // inserting values by using [] operator 
    for(int i=0;i<size;i++)
        umap[A[i]]++;
    // Traversing an unordered map
     for(int i=0;i<size;i++)
     {   
        //if the elemt of B is not in A
         if (umap.find(B[i]) == umap.end()) 
            return 0; 
        // if this element appears more number of times in A than in B
        if(umap[B[i]]==0)
            return 0;
        else
            umap[B[i]]--;
     }
    return 1;
}
int main() 
{ 
    // Declaring umap to be of <string, int> type 
    // key will be of string type and mapped value will 
    // be of double type 
    int T,N;
    long a1,a2;
    cin>>T;
    if(T<0 || T>100)
    {
        cerr<<"Illegal Value of test cases entered \n";
        return -1;
    }
    while(T>0)
    {
        T--;
        cin>>N;
        int n=0;
        long A[N],B[N];
        while(n<N)
        {
            cin>>a1;
            if(a1<0 || a1>pow(10,18))
                {
                    cerr<<"Illegal Value of element \n";
                    return -1;
                }
            A[n]=a1;
            n++;
        }
        n=0;
        while(n<N)
        {
            cin>>a2;
            if(a2<0 || a2>pow(10,18))
                {
                    cerr<<"Illegal Value of element \n";
                    return -1;
                }
            B[n]=a2;
            n++;
        }
        if(N<1 || N>pow(10,7))
            continue;
        cout<<compare(A,B,N)<<endl;
    }
    /*1 <= T <= 100
1 <= N <= 107
1 <= A[],B[] <= 1018*/
    return 0;
} 