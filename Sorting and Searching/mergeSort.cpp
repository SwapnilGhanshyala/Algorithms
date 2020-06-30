#include <iostream>
#include <vector>

using namespace std;
template <typename T>
void printVector(vector<T>* A)
{
    for(int i=0;i<A->size();i++)
        cout<<A->at(i)<<" ";;
    cout<<endl;
}
template <typename T>
vector<T> merge(vector<T> A,vector<T> B)
{
    int i=0,j=0;
    vector<T> C;
    while(i<A.size() && j<B.size())
    {
        if(A.at(i)>B.at(j))
            C.push_back(B.at(j++));
        else
            C.push_back(A.at(i++));
    }
    while(i<A.size())
        C.push_back(A.at(i++));
    while(j<B.size())
        C.push_back(B.at(j++));
    return C;
}
template <typename T>
vector<T> mergeSort(vector<T>* V)
{
if(V->size()==1)
    {
        vector<T> A;
        A.push_back(V->at(0));
        return A;
    }
int mid=(V->size()-1)/2;//mid=1
vector<T> V1,V2;
for(int i=0;i<=mid;i++)
    {V1.push_back(V->at(i));
    //printVector(&V1);
    }
for(int i=mid+1;i<V->size();i++)
    {V2.push_back(V->at(i));
    //printVector(&V2);
    }
V1=mergeSort(&V1);
V2=mergeSort(&V2);
return merge(V1,V2);
}
int main()
{
    vector<int> V={15,13,11,6,5,2};
    printVector(&V);
    cout<<"sorted array is\n";
    V=mergeSort(&V);
        printVector(&V);

}
