#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
template <typename T> struct sortedLL
{
vector<T> list;
void insert(T elem)
{
    if(list.size()==0)
    {
        list.push_back(elem);
        return;
    }
    
    vector<T>::iterator ptr; 
    for (ptr = list.begin(); ptr < list.end(); ptr++)
    {
        if(*ptr>elem)
        {
            list.insert(ptr,elem); 
            return;
        }
    }
}
vector<T>::iterator lookUpFirst(T elem)
{

}
void delete(T elem)//with linear search
{
    if(list.empty())
        return;
    vector<T>::iterator itr,start=NULL,end=NULL;
    for(itr=list.begin();itr<list.end();itr++)
        if(*itr==elem)
        {
            if(start==NULL)
                {start=itr;end=itr+1;}
            else
                end=itr+1;
        }
    list.erase(start,end);

}
bool binsearch(T elem,int start,int end)
{
   if(list.empty())
    return false;
    if(start>end)
        return false;
    mid=(start+end)/2;
    if(elem==list.at(mid))
        return true;
    if(elem<list.at(mid))
        return binsearch(elem,start,mid-1);
    else
        return binsearch(elem,mid+1,end);
    
}
};