#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void printVector(vector<T>* A)
{
    for(int i=0;i<A->size();i++)
        cout<<A->at(i)<<" ";;
    cout<<endl;
}
int searchValueInRotatedArray(vector<int> v,int n)
{
    int numberOfIterations=0;
    int l=0,u=v.size()-1;
    int m;
    while(l<=u)
    {
        numberOfIterations++;
        m=(l+u)/2;
        if(n==v.at(m))
           { 
               cout<<"NumberOf Iterationes are :"<<numberOfIterations<<endl;
               return m;
           }
        if(n<v.at(m))
        {
            if(n>v.at(l))
                u=m-1;
            else
                l=m+1;
        }
        else
        {
            if(n<v.at(u))
                l=m+1;
            else
                u=m-1;
        }       
    }
    cout<<"Not Found : NumberOf Iterationes are :"<<numberOfIterations<<endl;
    return -1;
}
/*
int findValueInRotatedArray(vector<int> A, int n)
{
    int m=A.size()/2;
    int num_itr=0;
    while(A.at(m)!=n)
    {
        if(n>A[m])
            if(m==A.size()-1)
                m=A.size()/4;
            else
                m=(m+A.size())/2;
        else
            if(m==0)
                m=(3*A.size())/4;
            else
                m=m/2;
        if(m==A.size()/2)
            {
                cout<<"Not found: number of iterations: "<<num_itr<<endl;
                return -1;
            }
    }
    cout<<"Number of itrs are :"<<num_itr<<endl;
    return m;
}*/
int main()
{
    vector<int> A={15,16,19,20,25,1,3,4,5,7,10,14};
    cout<<searchValueInRotatedArray(A,5)<<endl;
    return 1;
}