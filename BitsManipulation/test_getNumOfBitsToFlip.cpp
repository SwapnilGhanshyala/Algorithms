#include<iostream>
#include "bitsManipulation.h"
using namespace std;

int main()
{
    int N,M;
    cout<<"Enter the first number\n";
    cin>>N;
    cout<<"Enter the second  number\n";
    cin>>M;
    int diff=getNumOfBitsToFlip(N,M);
    cout<<"The number of bits to flip are : "<<diff<<"\n";
    return 0;
}