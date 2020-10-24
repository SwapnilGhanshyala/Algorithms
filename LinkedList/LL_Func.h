#include <iostream>

using namespace std;
template <typename T>
struct Node
{
    T data;
    Node* next;
   /* void mergeSort(int size)
    {
        Node * mid=split();
        mergeSort(size/2)


    }*/
};
template <typename T> using SNode=Node<T> *;

//printing the LinkedList
template <typename T>
struct SinglyLinkList
{
    SNode<T>   head;
    SNode<T>   tail;
    int size;
//creates a new LL and returns it
    
    void createList()
    {
        int N;
        cout<<"Enter the length:\n";
        cin>>N;
        if(N<=0)
        {
            head=NULL;
            tail=NULL;
            size=0;
            return;
        }
        size=N;
        SNode<T>  p=new Node<T>;
        int n;
        cout<<"Enter the data:\n";
        cin>>n;
        p->data=n;
        p->next=NULL;
        head=p;
        for(int i=0;i<N-1;i++)
        {
            cout<<"Enter the data:\n";
            cin>>n;
            SNode<T>  x=new Node<T>;
            x->data=n;
            x->next=NULL;
            p->next=x;
            p=x;
        }
        tail=p;
    }
    void print_LL()
    {
        if(head==NULL)
            return;
        SNode<T>  p=head;
        cout<<"The list is :";
        cout<<"\n\n";
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<"\n\n";
    }
//inserting/pushing an element at the end of the LL
    void insert(T value)
    {
        SNode<T>  p=new Node<T>;
        p->data=value;
        p->next=NULL;
        if(tail==NULL)
        {
            tail=p;
            head=p;
            size=1;
            return;
        }
        tail->next=p;
        tail=p;
        size++;
    }
    void insert_Node(SNode<T>   n)
    {
        if(n==NULL)
            return;
        if(tail==NULL)
        {
            tail=n;
            head=n;
            size=1;
            return;
        }
        tail->next=n;
        tail=tail->next;
        size++;
    }
//returns length of the LL
    int getLength()
    {
        return size;
       /* if(head==NULL)
            return 0;
        if(head->next==NULL)
            return 1;
        int length=1;
        SNode<T>  p=head;
        while(p->next)
        {
            length++;
            p=p->next;
        }
        return length;*/
    }
    void deleteElement(T elem)
    {
        if(head==NULL)
            return;
        while(head->data==elem)
        {
            SNode<T> p=head;
            head=head->next;
            p->next=NULL;
            if(head==NULL)
                return;
        }
        SNode<T> prev=head;
        SNode<T> p=head->next;
        while(p)
        {
            if(p->data==elem)
            {
                prev->next=p->next;
                p->next=NULL;
                p=prev->next;
            }
        }
    }
    //delete the Nth Node<T>of the head
    void deleteNode( int n)
    {
        if(head==NULL || n<=0)
            return;
        if(n>size)
        {
            cout<<"Invalid element to delete\n";
            return;
        }
        if(n==1)
        {
            SNode<T>  p=head;
            head=head->next;
            p->next=NULL;
            size--;
            return;
        }
        int c=2;
        SNode<T>  prev=head;
        SNode<T>  p=head->next;
        while(p)
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
        size--;
    }

//returns a pointer to the nth node
    SNode<T>   getNode(int n)
    {
        if(n>size)
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
            return head;
        SNode<T> p=head;
        int i=1;
        while(p)
        {
            if(i==n)
                break;
            i++;
            p=p->next;
        }
        return p;
    }
    void merge(SinglyLinkList*  list1)
    {
        if(list1==NULL ||list1->head==NULL)
            return;
        SNode<T> nodes=list1->head;
        if(tail==NULL)
        {
            head=nodes;
            size=1;
            tail=nodes;
            nodes=nodes->next;
            while(nodes)
            {
                size++;tail=nodes;
                nodes=nodes->next;
            }
            return;
        }
        tail->next=nodes;
        tail=nodes;
        nodes=nodes->next;
        while(nodes)
        {
            size++;tail=nodes;
            nodes=nodes->next;
        }
    }
//reverses a LL and returns a pointer to its head
    void reverse()
    {
        if(head==NULL || head->next==NULL)
            return ;
        SNode<T>  p=head;
        SNode<T>  rev= new Node<T>;
        rev->data=p->data;
        rev->next=NULL;
        p=p->next;
        tail=rev;
        while(p)
        {
            SNode<T>  n=new Node<T>;
            n->data=p->data;
            n->next=rev;
            rev=n;
            p=p->next;
        }
        head=rev;
}
  bool lookUp(T value)
  {
      if(head==NULL)
        return false;
      SNode<T> p=head;
      while(p)
      {
          if(p->data==value)
            return true;
            p=p->next;
      }
      return false;
  }  
  /*void sort()
  {
      head->mergeSort(0,size);
  }*/
};