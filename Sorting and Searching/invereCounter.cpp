#include <iostream>
#include <vector>
using namespace std;
int counter=0;
template <typename T>
void printVector(vector<T>* A)
{
    for(int i=0;i<A->size();i++)
        cout<<A->at(i)<<" ";;
    cout<<endl;
}
void merge(vector<int>* V,int start,int mid,int last)
{
    int i=start,j=mid+1;
    vector<int> C;
    while(i<=mid && j<=last)
    {
        if(V->at(i)>V->at(j))
        {
            //if value at j is less than value at i then it is less than all 
            //values from i to mid, which is mid-i+1
            C.push_back(V->at(j++));
            counter+=mid-i+1;
        }
        else
            C.push_back(V->at(i++));
    }
    //either 1 of these while loops will run
    while(i<=mid)
    {
        /*if the values at lower positions are remaining , that means,
        they were greater that all the values from mid+1 to last*/
        //counter+=last-mid;
        C.push_back(V->at(i++));
    }
    while(j<=last)
    {
        C.push_back(V->at(j++));
    }
    j=0;
    //cout<<"Counter after the merge is "<<counter<<endl;
    for(i=start;i<=last;i++)
        V->at(i)=C.at(j++);
}
void mergeCount(vector<int>* V,int start,int last)
{
    //cout<<"In mergeCount with : "<<start<<", "<<last<<endl;
    
    int mid=(start+last)/2;
    if(start<last)
    {
        mergeCount(V,start,mid);
        mergeCount(V,mid+1,last);
    //cout<<"Merging "<<start<<" to "<<mid<<" and "<<mid+1<<" to "<<last<<endl ;
        merge(V,start,mid,last);
    }
}
int main() {
/*1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018*/
int T,N,C;
cin>>T;
while(T>0)
{
    T--;
    cin>>N;
    int i=0;
    vector<int> V;
    while(i<N)
    {
        cin>>C;
        V.push_back(C);i++;
    }
    mergeCount(&V,0,N-1);
    cout<<counter<<endl;
    //printVector(&V);
    
}return 0;
}