#include <iostream>
#include "bitsManipulation.h"

using namespace std;
int main()
{
    int N,M;
    unsigned int i,j;
    cout<<"Specify the number to be changed\n";
    cin>>N;
    cout<<"Specify the number to update with\n";
    cin>>M;
    cout<<"Specify the start or ith position\n";
    cin>>i;
    cout<<"Specify the last or jth position\n";
    cin>>j;
    
    if(i<0 || i>=32 || j<0 || j>=32)
    {
        cerr<<"invalid i or j";
        return 1;
    }
    cout<<"\n\nPrint till here:/n/n/n/n";
    int count=0;
    while(count++<100)
        cout<<"here 6\n\n\n";
    int updated_N= updateBits(N,M,i,j);
    cout<<updated_N<<endl;
    count=0;
    while(count++<100)
        cout<<updated_N<<"\n\n\n";
    return 0;
}