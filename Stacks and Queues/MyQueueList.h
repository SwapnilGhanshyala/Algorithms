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
struct myQueue
{
cell* front;
cell*  tail;
myQueue()
{
    front=tail=NULL;
}
void clear()
{
    front=tail=NULL;
}
T getElement()
{
    if(tail==NULL)
        return -999;
    retrun tail->data;
}
bool dequeue()
{
    if(tail==NULL)
        return false;
    tail=tail->prev;
    if(tail)
        tail->next=NULL;
    return true;
}
void enqueue(T element)
{
    cell<T>* newNode=new cell<T>;
    cell->data=element;
    cell->next=NULL;
    if(tail==NULL)
    {
        front=tail=cell;
        tail->prev=NULL;
    }
    tail->next=cell;
    cell->prev=tail;
    tail=cell;  
}
};