#include <iostream>
#include <stack>
#include <string>

using namespace std; 

struct Stick
{
string name;
stack<int> st;
};
class TowerOfHanoi
{
public:
void solve(int N)
{
    Stick x,y,z;
    x.name="x";
    y.name="y";
    z.name="z";
    int n=N;
    cout<<"Assigning disks to x\n";
    while(n>0)
    {
        x.st.push(1);
        cout<<"Assigned "<<n<<"th disk\n";
        n--;
    }
    cout<<"the original tower\n";
    cout<<x.st.size()<<endl;
    cout<<y.st.size()<<endl;
    cout<<z.st.size()<<endl;

toh(N,&x,&y,&z);
    cout<<"\n After the transfer\n";
    cout<<x.st.size()<<endl;
    cout<<y.st.size()<<endl;
    cout<<z.st.size()<<endl;
}
//s1 to s2
void move(Stick *s1, Stick *s2)
{
    s1->st.pop();
    s2->st.push(1);
} 
 void toh(int N, Stick *x, Stick *y, Stick *z)
{
if(N==2)
{
    move(x,y);
    move(x,z);
    move(y,z);
    return;
}
cout<<"recursion n="<<N<<"\n";
toh(N-1,x,z,y);
move(x,z);
toh(N-1,y,x,z);
}
};

int main()
{
    cout<<"Enter the number of disks\n";
    int N;
    cin>>N;
    TowerOfHanoi ob;
    ob.solve(N);
    return 0;
}