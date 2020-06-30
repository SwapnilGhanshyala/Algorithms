#include <iostream>
#include "bitsManipulation.h"

using namespace std;

int main()
{
    int N;
    cout<<"Enter the number :\n";
    cin>>N;
    int new_N=swapOddEvenbits(N);
    cout<<"The new value is :"<<new_N<<"\n";
    return 0;
}