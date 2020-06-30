#include <iostream>
#include <string>
#include "bitsManipulation.h"

int main()
{   
    string N;
    cout<<"Enter the non-negative value you want to print the binary representation for:\n";
    cin>>N;
    printBinaryRep(N);
    return 0;
}