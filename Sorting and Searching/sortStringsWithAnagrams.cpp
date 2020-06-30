/*Write a method to sort an array of strings so that all the anagrams are next to each
other*/
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include "../Strings/stringFunctions.h"

using namespace std;

template <typename T>
void printVector(vector<T>* A)
{
    for(int i=0;i<A->size();i++)
        cout<<A->at(i)<<" ";;
    cout<<endl;
}
int compareForAnagrams(string str1,string str2)
{
    if(str1.empty() || str2.empty())
    {
        cout<<"Either string is empty\n";
        cout<<str1<<endl;
        cout<<str2<<endl;
        return false;
    }
    if (str1.compare(str2) == 0)
        return 0;
    // Sort both the strings 
    sort(str1.begin(), str1.end()); 
    sort(str2.begin(), str2.end()); 
    // Compare sorted strings 
    return str1.compare(str2);
}
void sortWithAnagrams(vector<string>* arr)
{
    vector<string> arr1;
    //printVector(&arr1);
    string t="";
    for(int i=0;i<arr->size()+1;i++)
    {
        t="";
        for(int j=i+1;j<arr->size();j++)
        {
           if(compareForAnagrams(arr->at(i),arr->at(j))>0)
           {
               t=arr->at(j);
               arr->at(j)=arr->at(i);
               arr->at(i)=t;
           } 
        }
    }

}
int main()
{
    vector<string> arr={"hi","my","name","emna","ih","is"};
    sortWithAnagrams(&arr);
    printVector(&arr);
}