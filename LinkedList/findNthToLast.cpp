#include <iostream>
#include "LL_Func.h"
int main()
{
    Node* head=createList();
    cout<<"The list is:\n ";
 print_LL(head);
 cout<<"end\n";
    int N;
    cout<<"Enter the Nth to last element you want to find:\n";
    cin>>N;
    if(N<0)
    {
        cerr<<"Invalid value";
        return 1;
    }
    int length=getLength(head);
    Node *n=getNthNode(head,length-N);
    cout<<"data is "<<n->data<<"\n";;
    return 0;
}