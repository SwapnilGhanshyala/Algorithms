
#include <iostream>
#include <vector>

using namespace std;
void printArray(int arr[],int size)
{
    cout<<"Array is:\n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
template <typename T>
void printVector(vector<T>* A)
{
    for(int i=0;i<A->size();i++)
        cout<<A->at(i)<<" ";;
    cout<<endl;
}
//solve with array for trial;
void mergeArrays(int A[],int lpos_A,int size_A,int B[],int lpos_B,int size_B)
{

    if(lpos_A+lpos_B+1>size_A)
    {
        cout<<"A cannot fit B\n";
        return;
    }
    for(int a=0,b=0;a<size_A;)
    {
        while(B[b]<A[a])
        {
            int t=A[a];
            A[a]=B[b];
            int i=0;
            lpos_A++;
            for(i=a+1;i<=lpos_A;i++)
            {
                int z=A[i];
                A[i]=t;
                t=z;
            }
            a++;b++;
            if(b==size_B)
                return;
        }
        a++;
    }
}
void mergeVectors(vector<int>* A,vector<int>* B)
{
    vector<int> :: iterator it_a=A->begin();
    vector<int> :: iterator it_b=B->begin();
    for(;it_a!=A->end(),it_b!=B->end();)
    {
        while(*it_b<*it_a)
        {
            A->insert(it_a,*it_b);
            it_a++;
            it_b++;
            if(it_a==A->end() && it_b!=B->end())
            {
                while(it_b!=B->end())
                {
                    A->push_back(*it_b);
                    it_b++;
                }
                return;
            }
            if(it_b==B->end())
                return;
        }
        it_a++;
    }
}
int main()
{
    int A[9]={1,3,5,9,12,0,0,0,0};
    printArray(A,5);
    int size_A=sizeof(A)/sizeof(A[0]);
    int B[4]={1,2,3,4};
    printArray(B,4);
    int size_B=sizeof(B)/sizeof(B[0]);
    mergeArrays(A,4,9,B,3,4);
    printArray(A,9);
    /*vector<int> A;
    A={1,3,5,9,12};
    A.push_back(15);
    printArray(&A);
    vector<int> B={1,2,3,4};
    mergeVectors(&A,&B);
    printArray(&A);
    */
   return 1;
}