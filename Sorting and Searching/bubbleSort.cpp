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
void bubbleSort(vector<T>* V)
{
    if(V->empty())
    {
        cout<<"Array is empty\n";
        return;
    }
    bool flag=true;
    int numPass=0,i;
    for( i=0;i<V->size()-1 && flag;i++)
    {
        flag=false;
        for(int j=0;j<V->size()-1-i;j++)
        {
            if(V->at(j)>V->at(j+1))
            {
                T t=V->at(j);
                V->at(j)=V->at(j+1);
                V->at(j+1)=t;
                flag=true;
            }
        }
        numPass++;
    }
    cout<<"Loop counter is :"<<i<<endl;
    cout<<"Number of passes : "<<numPass<<endl;
    printVector(V);
}
int main()
{
    vector<int> V={15,13,11,6,5,2};
    printVector(&V);
    cout<<"sorted array is\n";
    bubbleSort(&V);
}
