/*Given an integer, print the next smallest and next largest number that have the same
number of 1 bits in their binary representation.*/
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include "bitsmanipulation.h"

using namespace std;
int main()
{
    int N;
    cout<<"Enter the number:\n";
    cin>>N;
    string N_str=getBinaryRep(N);
    cout<<"Binary rep is : "<<N_str<<"\n";
    int countOnes=count(N_str.begin(), N_str.end(), '1'); 
    int max=0,min=0;
    int index_max=30,index_min=0;
    while(countOnes>0)
    {
        max+=pow(2,index_max--);
        min+=pow(2,index_min++);
        countOnes--;
    }
    cout<<"max value is: "<<max<<"\n";
    cout<<"min value is:"<<min<<"\n";
    return 0;
}
