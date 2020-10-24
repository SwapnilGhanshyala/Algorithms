#include <iostream>
using namespace std;
template<typename T>
struct cell
{
    T data;
    cell* next;
    cell* prev;
};

template<typename T>
struct mystack
{
    cell<T>* top;
    mystack()
    {
        top=NULL;
    }
    void clear()
    {
        top=NULL;
    }
    bool isEmpty()
    {
        return (top==NULL);
    }
    T top()
    {
        if(top==NULL)
            {cout<<"Empty Stack\n";return 0;}
        return top->data;
    }
    bool pop()
    {
        if(top==NULL)
            return false;
        top=top->prev;
        if(top!=NULL)
            top->next=NULL;
        return true;    
    }
    bool push(T elem)
    {
        cell<T>* newNode=new cell<T>;
        newNode->data=elem;
        newNode->next=NULL;
        if(top==NULL)
        {
            top=newNode;
            top->prev=NULL;
            return true;
        }
        newNode->prev=top;
        top=newNode;
        return true;
    }
};