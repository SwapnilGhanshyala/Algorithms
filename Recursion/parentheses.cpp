/*Implement an algorithm to print all valid (e.g., properly opened and closed)
 combinations of n-pairs of parentheses.
EXAMPLE:
input: 3 (e.g., 3 pairs of parentheses)
output: ()()(), ()(()), (())(), ((()))*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getAllPossibleCombinations(int N)
{
    vector<string> combinations;
    if(N==1)
    {
        combinations.push_back("()");
        return combinations;
    }
    vector<string> remaining_combos=getAllPossibleCombinations(N-1);
    for(int i=0;i<remaining_combos.size();i++)
    {
        combinations.push_back("()"+remaining_combos.at(i));
        combinations.push_back("("+remaining_combos.at(i)+")");
        //combinations.push_back(remaining_combos.at(i)+"()");
    }
    return combinations;
}

void printAllValidCombinations(int N)
{
    if(N<=0)
    {
        cout<<"Invalid number of parentheses\n";
        return;
    }
    vector<string> parenthesesCombos=getAllPossibleCombinations(N);
    for(int i=0;i<parenthesesCombos.size();i++)
    {
        cout<<parenthesesCombos.at(i)<<"\n";
    }
    cout<<"\n\n";
}
int main()
{
    int N;
    cout<<"Enter the number of pairs of parentheses \n";
    cin>>N;
    printAllValidCombinations(N);
    return 1;
}