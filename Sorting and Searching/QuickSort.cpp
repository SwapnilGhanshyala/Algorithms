/*Code to implement the Quick sort Algorithm */

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
int partition(vector<T>* V,int start,int end)
{
    T elem=V->at(start);
    int q=start;
    for(int i=start+1;i<=end;i++)
    {
        if(V->at(i)<elem)//if the value is smaller that selected element: SWAP
        {
            int t=V->at(i);
            V->at(i)=V->at(++q);
            V->at(q)=t;
        }
    }
    int t=V->at(q);
    V->at(q)=elem;
    V->at(start)=t;
    return q;
}
template <typename T>
void QuickSortVector(vector<T>* V, int start, int end)
{
    //if(start>=end)
       // return;
    if(start<end)
    {
        int q=partition(V,start,end);
        if(start<q-1)
        QuickSortVector(V,start,q-1);
        if(q+1<end)
        QuickSortVector(V,q+1,end);
    }
}

template <typename T>
void printVector(vector<T>* A)
{
    for(int i=0;i<A->size();i++)
        cout<<A->at(i)<<" ";;
    cout<<endl;
}
int main()
{
    vector<int> A={2,5,1,34,7,8,12,6,9};
    QuickSortVector(&A,0,8);
    printVector(&A);
    return 1;
}