/* Write a method that returns all subsets of a set.*/
#include <iostream>
#include <set>

using namespace std;
void printSet(set<int> s)
{
    if(s.empty())
        cout<<"@";
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<" ";
        }
    cout<<"\n\n";
}
set<set<int>> getAllSubsets(set<int> s)
{
    cout<<"Recursion for:\n";
    printSet(s);
    set<set<int>> allsubsets={{}};
    if(s.empty())
    {
        cout<<"Illegal set, set is empty\n";
        return allsubsets;
    }
    //allsubsets.insert({});//inserting null set
    //cout<<"Null set inserted\n";
    if(s.size()==1 && *(s.begin())==0)
    {
        allsubsets.insert({*(s.begin())});
        return allsubsets;
    }
    set<int> subset;
    for (set<int>::iterator it=s.begin(); ;)
        {
            int v=*it;
            if(++it==s.end())
                break;
            subset.insert(v);       
        }
    //cout<<"Printing the subset\n";
    //printSet(subset);
    set<set<int>> subsets;
    //if(!subset.empty())
        subsets=getAllSubsets(subset);
    //else
    //    subsets=getAllSubsets({});
    int value=(*s.end());
    cout<<"the seperated value is : "<<value<<"\n";
    for(set<set<int>>::iterator it=subsets.begin();it!=subsets.end();++it)
    {
        set<int> comboSet=*it;
        //cout<<"Printing the combo subset\n";
        //printSet(subset);
        allsubsets.insert(comboSet);
        comboSet.insert(value);
        allsubsets.insert(comboSet);
    }
    return allsubsets;
} 
int main()
{
    int N;
    cout<<"Enter the value till which set has to be created automatically\n";
    cin>>N;
    set<int> s={};
    for(int i=1;i<=N;i++)
        s.insert(i);
    cout<<"Print the set\n";
    printSet(s);
    set<set<int>> powerset=getAllSubsets(s);
    cout<<"Subsets created successfully\n";
    if(powerset.size()==0)
    {
        cout<<"PowerSet is empty\n";
        return -1;
    }   
    for(set<set<int>>::iterator it=powerset.begin();it!=powerset.end();it++)
    {
        set<int> subset=*it;
        //cout<<"Reached here 1\n";
        printSet(subset);        
    }
    return 0;
}
