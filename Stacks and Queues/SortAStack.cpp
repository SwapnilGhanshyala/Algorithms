/*Sort a stack in ascending order using push/pop/peek/isEmpty*/
#include <iostream>
#include <stack>

using namespace std;
template <typename T> 

void sortStack(stack<T> *s)
{
    if(s->empty())
    {
        cerr<<"Empty array to sort\n";
        return;
    }
    if(s->size()==1)
    {
        return;
    }
stack<T> a,b;
a.push(s->top());
s->pop();
while(!s->empty())
{
    while(!a.empty())
    {
        if(a.top()<s->top() )
        {
            break;
        }
        b.push(a.top());
        a.pop();
    }
    a.push(s->top());
    s->pop();
    while(!b.empty())
    {
        a.push(b.top());
        b.pop();
    }
}
s->swap(a);
}
int main()
{
int N;
cout<<"Enter the number of values you want to sort\n";
cin>>N;
int n=0,value=0;
stack <int> s;
while(n<N)
{
cout<<"Enter the value \n";
cin>>value;
s.push(value);
n++;
}
sortStack(&s);//sort array in ascending order
cout<<"Sorted Stack is: \n";
stack<int> rev;
while(!s.empty())
{
rev.push(s.top());
s.pop();
}
while(!rev.empty())// print array in ascending order
{
    cout<<rev.top()<<"\n";
    rev.pop();
}
return 0;
}