#include <iostream>
using namespace std;

/*You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
method to set all bits between i and j in N equal to M*/
//bit index starts from 0-N , right to left
int updateBits(int N,int M, unsigned int i,unsigned int j)
{
    if(i>j)
    {
        cout<<"Illegal positions specified\n";
        return -999;
    }
    //int mask=(~0)<<j;//this might be messing up the MSB
    int mask=~0;
    int count=0;
    while(count++<100)
        cout<<"here 1\n\n\n";
    int right=(1<<j)-1;
    count=0;
    while(count++<100)
        cout<<"here 2\n\n\n";
    count=0;
    int mask_invert=right&(~0<<i);
    count=0;
    while(count++<100)
        cout<<"here 3\n\n\n";
    count=0;
    mask=mask-mask_invert;
    while(count++<100)
        cout<<"here 4\n\n\n";
    count=0;
    int result=(N & mask)|(M<<i);
    while(count++<100)
        cout<<"here 5\n\n\n";
    count=0;
    return result;
}