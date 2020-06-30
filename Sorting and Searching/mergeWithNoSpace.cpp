#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
template <typename T>
void printVector(vector<T>* A,vector<T>* B)
{
    for(int i=0;i<A->size();i++)
        cout<<A->at(i)<<" ";;
    for(int i=0;i<B->size();i++)
        cout<<B->at(i)<<" ";

    cout<<endl;
}
int partition(vector<int>* A,vector<int>* B,int Astart,int Alast,int Bstart,int Blast)
{
    if(Astart!=-1 && Blast!=-1)//start in A and end in B
    {
        int elem=A->at(Astart);
        int q=Astart;
        int b=0,i=Astart+1;
        while(i<=Alast)
        {
            if(A->at(i)<elem)
            {            
            int t=A->at(i);
            A->at(i)=A->at(++q);
            A->at(q)=t;
            }
            i++;
        }
        i=0;
        while(i<=Blast)
        {
            if(B->at(i)<elem)
            {
                if(q<Alast)
                {
                    int t=B->at(i);
                    B->at(i)=A->at(++q);
                    A->at(q)=t;
                }
                else
                {
                    int t=B->at(i);
                    B->at(i)=B->at(b);
                    B->at(b++)=t;
                }
            }
            i++;
        }
        if(b!=0)//pivot in B
        {
            int t=B->at(b-1);
            B->at(b-1)=elem;
            A->at(Astart)=t;
            return (b+A->size()-1);
        }
        else
        {
            if(q!=Astart)
            {
                A->at(Astart)=A->at(q);
                A->at(q)=elem;
            }
            return q;
        }
    }
    else
    {
        if(Astart==-1 && Blast!=-1)//Partition on B only
        {
            int elem=B->at(Bstart);
            int q=Bstart;
            int i=Bstart+1;
            while(i<=Blast)
            {
                if(B->at(i)<elem)
                {
                int t=B->at(i);
                B->at(i)=B->at(++q);
                B->at(q)=t;
                }
                i++;
            }
            if(q!=Bstart)
            {
                B->at(Bstart)=B->at(q);
                B->at(q)=elem;
            }
            return q;
        }
        else{
            if(Astart!=-1 && Blast==-1)
            {
                int elem=A->at(Astart);
                int q=Astart;
                int i=Astart+1;
                while(i<=Alast)
                {
                    if(A->at(i)<elem)
                    {
                    int t=A->at(i);
                    A->at(i)=A->at(++q);
                    A->at(q)=t;
                    }
                    i++;
                }
                if(q!=Astart)
                {
                    A->at(Astart)=A->at(q);
                    A->at(q)=elem;
                }
                return q;
            }
        }
    }
    return -1;
}
void quickMerge(vector<int>* A,vector<int>* B,int Astart,int Alast,int Bstart,int Blast)
{
    if(Astart==-1 && Blast==-1)
    {
        return;
    }
    if(Astart<Alast || Bstart<Blast)//when should partitions be made
    {
        int q=partition(A,B,Astart,Alast,Bstart,Blast);

        if(q>=A->size())//pivot in B
        {
            q=q-A->size();
            if(q==0)
            {    
                quickMerge(A,B,Astart,Alast,-1,-1);
                quickMerge(A,B,-1,-1,q+1,Blast);
            } 
            else
            {
                quickMerge(A,B,Astart,Alast,Bstart,q-1);
                quickMerge(A,B,-1,-1,q+1,Blast);
            }    
        }
        else
        {
            if(Astart==-1)//pivot in B
            {
                quickMerge(A,B,-1,-1,Bstart,q-1);
                quickMerge(A,B,-1,-1,q+1,Blast);
            }
            else
            {
                if(Bstart==-1)//pivot in A
                {
                    quickMerge(A,B,Astart,q-1,-1,-1);
                    quickMerge(A,B,q+1,Alast,-1,-1);
                }
                else
                {
                    quickMerge(A,B,Astart,q-1,-1,-1);
                    if(q+1<=Alast)
                    quickMerge(A,B,q+1,Alast,Bstart,Blast);
                    else
                    quickMerge(A,B,-1,-1,Bstart,Blast);
                }
            }
        }

    }
}
int main()
{
    /*1 <= T <= 100
1 <= X, Y <= 5*104
*/
int T,X,Y,c1,c2;
cin>>T;
if(T<1 || T>100)
{
    cerr<<"Illegal Value of T\n";
    return -1;
}
while(T>0)
{
    T--;
    cin>>X;
    cin>>Y;
    if(X<1 || Y<1 || X>5*pow(10,4) || X>5*pow(10,4))
    {
        cerr<<"Illegal X or Y\n"<<endl;
        return -1;
    }
    int x=0,y=0;
    vector<int> A,B;
    while(x++<X)
    {
        /*0 <= arr1i, arr2i <= 109*/
        cin>>c1;
        if(c1<0 || c1>pow(10,9))
        {
            cerr<<"array value out of bounds\n";
            return -1;
        }
        A.push_back(c1);
    }
    while(y++<Y)
    {
        cin>>c2;
        if(c2<0 || c2>pow(10,9))
        {
            cerr<<"array value out of bounds\n";
            return -1;
        }
        B.push_back(c2);
    }
    quickMerge(&A,&B,0,X-1,0,Y-1);
    printVector(&A,&B);
}
return 0;
}