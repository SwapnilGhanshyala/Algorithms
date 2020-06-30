/*Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.
Example: find "ball" in ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""] will return 4
Example: find "ballcar" in ["at", "", "", "", "", "ball", "car", "", "", "dad", "", ""] will return -1*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void printVector(vector<T>* A)
{
    for(int i=0;i<A->size();i++)
        cout<<A->at(i)<<" ";;
    cout<<endl;
}
int searchInSortedArrayWithEmptyStrings(vector<string>* V, string str)
{
int first=0;
int last=V->size()-1;
while(V->at(first).empty())
    first++;
cout<<"Reached here 1\n";
if(V->at(first).compare(str)<0)
    return -1;
cout<<"Reached here 2\n";

while(V->at(last).empty())
    last--;
    cout<<"Reached here 3\n";

if(str.compare(V->at(last))>0)
    {
        cout<<str;
        return -1;}
cout<<"Reached here 4\n";

int mid=0;
while(first<last)
{
    cout<<"mid is :"<<mid<<endl;
    while(V->at(last).empty())
        last--;
    if(last<first)
        return -1;
    //mid=(last+first)>>1;
    mid=(last+first)/2;
    while(V->at(mid).empty())
        mid--;
    int comp=str.compare(V->at(mid));
    if(comp==0)
        return mid;
    if(comp>0)
        first=mid+1;
    else
        last=mid-1;
}
return -1;
}
int main()
{
    vector<string> V={"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    printVector(&V);
    string str="";
    cout<<"Enter the value you want to search\n";
    cin>>str;
    if(str.empty())
    {
        cout<<"Empty string entered\n";
        return -1;
    }
    int position=searchInSortedArrayWithEmptyStrings(&V,str);
    if(position==-1)
        cout<<"Value Not Found\n";
    else
        cout<<"Found at : "<<position<<endl;
    return 1;
}