/*Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can
only move in two directions: right and down. How many possible paths are there for
the robot?*/
#include <iostream>

using namespace std;
int numOfPaths(int N, int M)
{
    if(N<0 || M<0)
    {
        cout<<"Illegal number of paths \n";
        return N;
    }
    if(N==1 || M==1)
        return 1;
    if(N==2 && M==2)
        return 2;
    return numOfPaths(N-1,M)+numOfPaths(N,M-1);
}
int main()
{
    int N;
    cout<<"Enter number of columns in the grid\n";
    cin>>N;
    cout<<"The number of paths are :"<<numOfPaths(N,N)<<"\n";
    return 0;
}