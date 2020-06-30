#include <iostream>
#include <vector>
#include "setofstacks.cpp"
using namespace std;

int main()
{
    setOfStacks ob;
    cout<<"Enter Limit per stack\n";
    int L;
    cin>>L;
    ob.setLIMIT(L);
    bool flag=true;
    while(flag)
    {
        cout<<"Enter 1 for push\n";
        cout<<"Enter 2 for pop\n";
        cout<<"Enter 3 to pop at an indexed stack\n";
        cout<<"Enter 4 to exit\n";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter Value you want to push\n";
            int value;
            cin>>value;
            ob.push(value);
            cout<<"Successfully pushed element\n";
            break;
            case 2:
            ob.pop();
            cout<<"Successfully popped element\n";
            break;
            case 3:
            cout<<"Enter the index you want to pop\n";
            int index;
            cin>>index;
            ob.popAt(index);
            cout<<"Successfully popped element\n";
            break;
            case 4:
            flag=false;
            cout<<"Exit the menu\n";
            break;
            default:
            cout<<"Invalid choice entered\nTRY AGAIN\n";
        }
    }
return 0;
}
