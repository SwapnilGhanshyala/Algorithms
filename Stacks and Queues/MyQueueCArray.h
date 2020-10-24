#include <iostream>
using namespace std;

#define MAX 20;
template<typename T>
struct myCQueue
{
    T cqueue[MAX];
    int front;
    int tail;
    myCQueue()
    {
        front=-1,tail=-1;
    }
    //clear
    void clear()
    {
        front=-1,tail=-1;
    }
    bool isFull()
    {
        return (tail+1==front || (front=0 && tail=MAX-1));
    }
    //enqueue
    bool enqueue(T elem)
    {
        if(isFull())
            return false;
        if(front==-1)
            front=tail=0;
        else 
            if(tail=MAX-1)
                tail=0;
            else
                tail++;
        cqueue[tail]=elem;
        return true;
    }
    
    T getElememt()
    {
        if(front==-1)
            return -999;
        return cqueue[front];
    }
    bool dequeue()
    {
        if(tail=-1)
            return false;
        if(front==tail)
        {
            front=tail=-1;
            return true;
        }
        if(front==MAX-1)
            front=0;
        else
            front++;
    }
    int getSize()
    {
        if(front<=tail)
            return (tail-front+1);
        return MAX-front+tail+1;
    }
    bool dequeueN(int N)
    {
        if(front==-1)
            return false;
        int size=getSize();
        if(N>size)
            return false;
        if(N==size)
        {
            clear();
            return true;
        }
        while(N)
        {
            front++;
            if(front==Max)
                front=0;
            N--;
        }
        return true;
    }
};