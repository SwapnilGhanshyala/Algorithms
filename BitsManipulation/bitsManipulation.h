#include <iostream>
#include <string>
#include <bits/stdc++.h> 

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
    int right=(1<<j)-1;
    int mask_invert=right&(~0<<i);
    mask=mask-mask_invert;
    int result=(N & mask)|(M<<i);
    return result;
}
//this fxn assumes that N is positive integer FOR NOW
//TODO: same function for negative integers as well
string getBinaryRep(int N)
{
    if(N==0 || N==1)
        return to_string(N);
    string str_result="";
    int r;
    while(N>0)
    {
        r=N%2;
        str_result=to_string(r)+str_result;
        N=N/2;
    }
    return str_result;
}
string getBinaryRep(double N)
{
int front=N;
string result_str="";
if(front>0)
    result_str=getBinaryRep(front);
result_str+=".";
N=N-front;
if(N==0.0)
{
    result_str+="0";
    return result_str;
}
int count=0;
int r;
double d;
    while(N!=0.0 && count<32)
    {
        r=(N*2);
        N=(N*2)-r;
        count++;
        result_str+=to_string(r);
    }
    return result_str;
}
/*Given a (decimal - e.g. 3.72) number that is passed in as a string,
 print the binary representation.
 If the number can not be represented accurately in binary, print “ERROR”
*/
void printBinaryRep(string number_str)
{
    try{
        double decim=stod(number_str);
        string decim_str=getBinaryRep(decim);
        cout<<"Binary representation is:"<<decim_str<<"\n\n";
    }
    catch(...)
    {
        cerr<<"Illegal Value sent, cannot converted to binary: ERROR\n\n";
        return;
    }
}
/*Given 2 Numbers find the Number of bits to 
flip, so as to convert first number to second number*/
int getNumOfBitsToFlip(int N, int M)
{
    if(N==M)
        return 0;
    int X_result=N^M;
    string X_str=getBinaryRep(X_result);
    return count(X_str.begin(),X_str.end(),'1');
} 

//function to swap odd even bits
int swapOddEvenbits(int x)
{
    return ( ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1) );
}