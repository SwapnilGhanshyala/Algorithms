#include<iostream>
#include "LL_Func.h"

Node* addLLNum(Node *h1, Node *h2)
{
    if(h1==NULL || h2==NULL)
    {
        cerr<<"Invalid LL to be added: No Numbers\n";
        return NULL;
    }
    Node *p1=h1,*p2=h2,*p3;
    int sum=0,carry=0;
    sum=(p1->data)+(p2->data)+carry;
    carry=sum/10;
    Node *h3=new Node;
    h3->data=sum%10;
    h3->next=NULL;
    p3=h3;
    p1=p1->next;
    p2=p2->next;
    while(p1!=NULL && p2!=NULL)
    {
        sum=(p1->data)+(p2->data)+carry;
        carry=sum/10;
        Node *n=new Node;
        n->data=sum%10;
        n->next=NULL;
        p3->next=n;
        p3=p3->next;
        p1=p1->next;
        p2=p2->next;
    }
    while(p1!=NULL)
    {
        sum=p1->data+carry;
        carry=sum/10;
        Node *n=new Node;
        n->data=sum%10;
        n->next=NULL;
        p3->next=n;
        p3=p3->next;
        p1=p1->next;    
    }
    while(p2!=NULL)
    {
        sum=p2->data+carry;
        carry=sum/10;
        Node *n=new Node;
        n->data=sum%10;
        n->next=NULL;
        p3->next=n;
        p3=p3->next;
        p2=p2->next;
    }
    if(carry==1)
    {
        Node *n=new Node();
        n->data=1;
        n->next=NULL;
        p3->next=n;
    }
return h3;
}
//recieves numbers from user in reverse order and prints result in 
//numeric order
int main(){
    Node *head1=createList();
    Node *rev_head1=reverse_LL(head1);
    print_LL(rev_head1);
    Node *head2=createList();
    Node *rev_head2=reverse_LL(head2);
    print_LL(rev_head2);
    cout<<"Adding \n\n";
    Node *head3=addLLNum(head1,head2);
    Node *rev_head3=reverse_LL(head3);
    print_LL(rev_head3);
}