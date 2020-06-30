#include<iostream>
#include "LL_Func.h"

void deleteNodeWithAccess(Node *head,Node *n)
{
if(head==NULL)
{cerr<<"Invalid LL\n";
return;}
if(n==NULL)
{
    cerr<<"NULL node to delete";
    return;
}
if(head==n)
{
    head=head->next;
    n->next=NULL;
    return;
}
Node *prev=head;
Node *p=head->next;
int flag=0;
while(p!=NULL)
{
    cout<<"In while loop \n";
    if(n==p)
    {
            cout<<"Found a match \n";

        prev->next=p->next;
        p->next=NULL;
        flag=1;
        break;
    }
    prev=prev->next;
    p=p->next;
}
if(flag==0)
{
    cout<<"Intended Node not found\n";
}
}
int main()
{
    Node *head=createList();
    int N;
    cout <<"The position of Node to be deleted:\n";
    cin>>N;
    Node *n=getNthNode(head,N);
    cout<<"deleting node with data "<<n->data<<"\n";
    print_LL(head);
    deleteNodeWithAccess(head,n);
    print_LL(head);
}
