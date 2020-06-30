#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};
//printing the LinkedList
template <typename T>
void print_LL(Node<T> *root)
{
    if(root==NULL)
    {
    cout<<"Invalid LL to print";
    return;
    }
    Node<T> *p=root;
    cout<<"The list is :";
    cout<<"\n\n";
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n\n";
}
//inserting/pushing an element at the end of the LL
template <typename T>
void insert_end(Node<T> *n,Node<T> *root)
{
    Node<T> *p=root;
    while(p->next!=NULL)
    {p=p->next;}
    p->next=n;
}
//returns length of the LL
template <typename T>
int getLength(Node<T> *root)
{
    if(root==NULL)
    return 0;
    if(root->next==NULL)
    {cout<<"single node \n";return 1;}
    int length=0;
    Node<T> *p=root;
    while(p->next!=NULL)
    {
        length++;
        p=p->next;
    }
    return ++length;
}
//creates a new LL and returns it
template <typename T>
Node<T>* createList()
{
    int N;
    cout<<"Enter the length:"<<endl;
    cin>>N;
    if(N==0)
    {
     cerr<<"Invalid linked list length";
    }
    Node<T> *root=new Node<T>;
    int n;
    cout<<"Enter the data:"<<endl;
    cin>>n;
    root->data=n;
    root->next=NULL;
    Node<T> *p=root;
    for(int i=0;i<N-1;i++)
    {
        cout<<"Enter the data:"<<endl;
        cin>>n;
        Node<T> *x=new Node<T>;;
        x->data=n;
        x->next=NULL;
        p->next=x;
        p=x;
    }
    return root;
}
//delete the Nth Node<T>of the head
template <typename T>
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
template <typename T>
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
template <typename T>
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
}