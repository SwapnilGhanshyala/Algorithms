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
void insertionSort(vector<T>* V)
{
    if(V->empty())
    {
        cout<<"Array is empty\n";
        return;
    }
    bool flag=true;
    for(int i=0;i<V->size()-1;i++)// So max number of passes is n-1
    {
        for(int j=i+1;j<V->size();j++)
        {
            if(V->at(i)>V->at(j))
            {
                T t=V->at(i);
                V->at(i)=V->at(j);
                V->at(j)=t;
            }
        }
    }
    printVector(V);
}
int main()
{
    vector<int> V={15,13,11,6,5,2};
    printVector(&V);
    cout<<"sorted array is\n";
    insertionSort(&V);
}
