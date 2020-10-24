/*Implementing a Queue using 2 stacks*/
#include <iostream>
#include <stack>

using namespace std;

template <typename T> 

class MyQueue
{
    private:
stack <T> A;
stack <T> B;
public:
T dequeue()
{
    if(B.empty())
    {
        if(A.empty())
        {
            cerr<<"Queue is empty\n";
        }
        while(!(A.empty()))
        {
            B.push(A.top());
            A.pop();
        }
    }
    T value=B.top();
    B.pop();
    return value;
}
void queue(T value)
{
    A.push(value);
}
};

int main()
{
    MyQueue<int> ob;
    bool flag=true;
    while(flag)
    {
        cout<<"Enter 1 to queue\n";
        cout<<"Enter 2 to dequeue\n";
        cout<<"Eneter 3 for exit\n";
        int choice,n;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter the value you want to queue\n";
            cin>>n;
            ob.queue(n);
            break;
            case 2:
            n=ob.dequeue();
            cout<<"Value is "<<n<<endl;
            break;
            case 3:
            flag=false;
            break;
            default:
            cout<<"Invalid choice entered";
        }
    }
    return 0;
}