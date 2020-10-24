#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;

};
//template <typename T> using SNode=Node<T> *;
//printing the LinkedList
template <typename T>
struct SinglyLinkList
{
    Node<T> * front;
    Node<T> *  back;
//creates a new LL and returns it
    void createList()
    {
        int N;
        cout<<"Enter the length:\n";
        cin>>N;
        if(N==0)
            return;
        Node<T> * p=new Node<T>;
        int n;
        cout<<"Enter the data:\n";
        cin>>n;
        p->data=n;
        p->next=NULL;
        front=p;
        for(int i=0;i<N-1;i++)
        {
            cout<<"Enter the data:\n";
            cin>>n;
            Node<T> * x=new Node<T>;
            x->data=n;
            x->next=NULL;
            p->next=x;
            p=x;
        }
        back=p;
    }
    void print_LL()
    {
        if(front==NULL)
            return;
        Node<T> * p=front;
        cout<<"The list is :";
        cout<<"\n\n";
        while(p)
        {
            cout<<"Here 1\n";
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<"\n\n";
    }
//inserting/pushing an element at the end of the LL
    void insert_end(Node<T> * n)
    {
        back->next=n;
        back=back->next;
    }
//returns length of the LL
    int getLength()
    {
        if(front==NULL)
            return 0;
        if(front->next==NULL)
            return 1;
        int length=1;
        Node<T> * p=front;
        while(p->next)
        {
            length++;
            p=p->next;
        }
        return length;
    }
    /*
//delete the Nth Node<T>of the head
void deleteNthNode(Node<T>  *head, int n)
{
if(head==NULL || n<=0)
{
    cerr<<"Invalid value";
    return;
}
if(n>getLength(head))
{
    cout<<"Invalid element to delete\n";
    return;
}
if(n==1)
{
    Node<T> *p=head;
    head=head->next;
    p->next=NULL;
    return;
}
int c=2;
Node<T> *prev=head;
Node<T> *p=head->next;
while(p!=NULL)
{
    if(n==c)
    {
        prev->next=p->next;
        p->next=NULL;
        break;
    }
    prev=prev->next;
    p=p->next;
    c++;
}
}
//returns a pointer to the nth node
Node<T>* getNthNode(Node<T> *root,int n)
{
    int length=getLength(root);
    if(n>length)
    {
        cout<<"Invalid element requested";
        return NULL;
    }
    if(n<=0)
    {
        cerr<<"Invalid Node<T>\n";
        return NULL;
    }
    if(n==1)
    return root;
    Node<T> *p=root;
    int i=1;
    while(p!=NULL)
    {
        if(i==n)
        {
break;
        }
        i++;
        p=p->next;
    }
    return p;
}
//reverses a LL and returns a pointer to its head
Node<T>* reverse_LL(Node<T> *head)
{
    if(head==NULL)
    {
        cerr<<"Cannot reverse null LL";
        return NULL;
    }
    if(head->next==NULL)
        return head;
    Node<T> *rev,*p=head;
    rev=new Node<T>;
        rev->data=p->data;
        rev->next=NULL;
        p=p->next;
    while(p!=NULL)
    {
        Node<T> *n=new Node<T>;
        n->data=p->data;
        n->next=rev;
        rev=n;
        p=p->next;
    }
    return rev;
}*/
};