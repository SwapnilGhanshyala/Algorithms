/*method to return all possible permutations of a string*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> permuteString(string s)
{
    vector<string> allPermutations;
    if(s.empty())
    {
        cout<<"Invalid string: empty\n";
        return allPermutations;
    }
    if(s.size()==1)
    {
        allPermutations.push_back(s);
        return allPermutations;
    }
    if(s.size()==2)
    {
        string str=s.substr(1)+s.substr(0,1);
        allPermutations.push_back(s);
        allPermutations.push_back(str);
        return allPermutations;
    }
    for(unsigned int i=0;i<s.size();i++)
    {
        char ch=s.at(i);
        string str;
        if(i==0)
        {
            str=s.substr(i+1);
        }
        else
        {
            if(i==s.size()-1)
                str=s.substr(0,i);
            else
                str=s.substr(0,i)+s.substr(i+1);
        }
        vector<string> permutations=permuteString(str);
        for(int j=0;j<permutations.size();j++)
        {
            string n_str=permutations.at(j);
            n_str.insert(0,1,ch);
            allPermutations.push_back(n_str);
        }        
    }
    return allPermutations;

}
int main()
{
string s;
cout<<"Enter the string you want to find permutations for\n";
cin>>s;
vector <string> allpermutations=permuteString(s);
for(unsigned int i=0;i<allpermutations.size();i++)
{
    cout<<allpermutations.at(i)<<"\n";
}
return 1;
}