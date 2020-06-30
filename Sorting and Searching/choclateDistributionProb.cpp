/*Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students having packet with maximum chocolates and student having packet with minimum chocolates is minimum.*/
/*Input:
The first line of input contains an integer T, denoting the number of test cases.
Then T test cases follow. Each test case consists of three lines.
The first line of each test case contains an integer N denoting the number of packets.
Then next line contains N space separated values of the array A denoting the values of each packet.
The third line of each test case contains an integer m denoting the no of students.*/
#include <iostream>
#include <math.h>

using namespace std;
void printArray(long A[],int Asize)
{
    for(int i=0;i<Asize;i++)
        cout<<A[i]<<" ";;
    cout<<endl;
}
int compare(const void* a, const void* b)
{
	const long* x = (long*) a;
	const long* y = (long*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}
long distributeChocolate(long A[],int Asize,int M)
{
    qsort(A,Asize,sizeof(long),compare);
    printArray(A,Asize);
    int pos1=0,pos2=M-1;
    long minDiff=A[pos2]-A[pos1];
    for(int i=1;i<=Asize-M;i++)
    {
        long diff=A[i+M-1]-A[i];
        if(diff<minDiff)
        {
            minDiff=diff;
        }
    }
    return minDiff;
}
int main()
{
/*1 <= T <= 100*/
int T,N,c;
cin>>T;
if(T<0 || T>100)
{
    cerr<<"Illegal Value of T\n";
    return -1;
}
while(T>0)
{
    T--;
    cin>>N;
    int n=0;
    long  A[N];
    while(n<N)
    {
        cin>>c;
        if(c<0 || c>pow(10,18))
        {
            cerr<<"Illegal value entered in the array\n";
            return -1;
        }
        A[n]=c;
        n++;
    }
        //printArray(A,N);
        /*1 <=N<= 107
1 <= Ai <= 1018
1 <= M <= N*/
        if(N<1 || N>pow(10,7))
        {
            //cout<<"Illegal value of N "<<N<<"\n";
            //cout<<-1<<endl;
            continue;
        }
        int M;
        cin>>M;
        if(M<1 || M>N)
        {
            //cout<<-1<<endl;
            continue;
        }
    cout<<distributeChocolate(A,N,M)<<endl;
}
return 0;
}