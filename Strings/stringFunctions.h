#include <iostream>
#include <string>

using namespace std;

bool isAnagramOf(string str1, string str2)
{
    if(str1.empty() || str2.empty())
    {
        cout<<"Either string is empty\n";
        cout<<str1<<endl;
        cout<<str2<<endl;
        return false;
    }
    if(str1.size()!=str2.size())
    {
        return false;
    }
    if (str1.compare(str2) == 0)
        return true;
    // Sort both the strings 
    sort(str1.begin(), str1.end()); 
    sort(str2.begin(), str2.end()); 
  
    // Compare sorted strings 
    for (int i = 0; i < str1.size(); i++) 
        if (str1[i] != str2[i]) 
            return false; 
  
    return true;
}
int findNumOccurence(string str, char ch)
{
    if(str.empty())
        return 0;
    int counter=0;
    for(unsigned int i=0;i<str.size();i++)
    {
        if(str.at(i)==ch)
            counter++;
    }
    return counter;
}