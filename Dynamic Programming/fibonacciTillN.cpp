#include <iostream>
using namespace std;

void printFibonacci(int N)
{
    if(N==1)
        {cout<<1<<endl;
        return ;
        }
    if(N==2)
        {
        cout<<"1 1"<<endl;
        return;
        }
    int n=2;
    long a=1,b=1,c;
    
    cout<<a<<" "<<b;
    while(n<=N)
    {
        c=a+b;
        a=b;b=c;
        cout<<" "<<b;
        n++;
    }
    cout<<endl;
    
}
int main() {
    /*1<= T <=100
1<= N <=84*/
int T,N;
cin>>T;
while(T>=1)
{
    T--;
   cin>>N;
   if(N<1 || N>84)
    continue;
    printFibonacci(N);
}
	return 0;
}