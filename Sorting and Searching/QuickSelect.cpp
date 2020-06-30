#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

int partition(vector<int>* V,int start,int last)
{
    
    int elem=V->at(start);
    int q=start;
    for(int i=start+1;i<=last;i++)
    {
        if(V->at(i)<elem)//if the value is smaller that selected element: SWAP
        {
            int t=V->at(i);
            V->at(i)=V->at(++q);
            V->at(q)=t;
        }
    }
    if(q==start)
        return q;
    V->at(start)=V->at(q);
    V->at(q)=elem;
    return q;
}
void quickSelect(vector<int>* A,int K,int start,int last )
{
    int q=partition(A,start,last);
    //cout<<q<<endl;
    if(K==q-start+1)
    {
        cout<<A->at(q)<<endl;
        return;
    }
    else
    {
        if(K<q-start+1)
            last=q-1;
        else
        {
            K=K-q+start-1;
            start=q+1;
        }
        if(last==start+1)
        {
            int vstart=A->at(start),vlast=A->at(last);
            bool startSmall=(vstart<vlast);
            if(K==1)
            {
                cout<<(startSmall?vstart:vlast)<<endl;
                return;
            }
            else
            {
                cout<<(startSmall?vlast:vstart)<<endl;
                return; 
            }
        }
        quickSelect(A,K,start,last);
    }
}
int main() {
    /*1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N*/
int T,N,K;
cin>>T;
/*if(T<=0 || T>100)
{
    cerr<<"Invalid number of testcases\n";
    return -1;
}*/
while(T>0)
{
    T--;
    cin>>N;
    if(N<1 || N>pow(10,5) )
    {
        cerr<<"Invalid array size\n";
        return -1;
    }
    vector<int> A(N);
    int i=0;
    int n=N;
    //system("cls");
    while(N>0)
    {
        N--;
        cin>>A[i++];
        //cerr<<A[i-1]<<" ";
        if(A[i-1]<0 || A[i-1]>pow(10,5))
        {
            cerr<<"Invalid value entered in the array";
            return -1;
        }
    }
    //cerr<<endl;
    cin>>K;
    //cerr<<K<<endl;
    if(K<1 || K>n)
    {
        cerr<<"Invalid value of K entered \n";
        return -1;
    }
    if(A.size()==1)
    {
        cout<<A.at(0)<<endl;
        return 0;
    }
    if(A.size()==2)
    {
        int vstart=A.at(0),vlast=A.at(1);
        bool startSmall=(vstart<vlast);
        if(K==1)
        {
            cout<<(startSmall?vstart:vlast)<<endl;
            return 0;
        }
        else
        {
            cout<<(startSmall?vlast:vstart)<<endl;
            return 0; 
        }
    }
    quickSelect(&A,K,0,A.size()-1);
    
}
	return 0;
}