#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template <typename T>
struct MaxHeap_Array
{
    unsigned int last;
    //unsigned int size;
    vector<T> A;  
    T front()
    {
        if(A.empty())
        {
            cout<<"heap is empty\n";
            return -999;
        }
        return A[0]; 
    }
    void pop_front()
    {
        A.at(0)=-999;
        heapify(0);
    }
    void insert(T value)
    {
        A.push_back(value);
        unsigned int position=A.size()-1;
        //fixing the heap
        if(A.size()==1)
        {
            last=0;
            return;
        }
        last++;
        unsigned int parent=floor(position/2);
        while(A.at(parent)<=value)
        //parent of the current position is less than the value
        {
            T t=A.at(parent);
            A.at(parent)=value;
            A.at(position)=t;
            position=parent;
            parent=floor(position/2);
            if(parent==position)//root: done
                break;
        }
    }  
    void printHeap()
    {
        for(int i=0;i<=last;i++)
            cout<<A.at(i)<<" ";
        cout<<"\n\n";
    }
    void deleteValue(unsigned int position)
    {
        if(position>last)
        {
            cout<<"Illegal position to delete\n";
            return;
        }
        //fixing when delete
        A.at(position)=-999;
        heapify(position);   
        while(A.at(last)==-999)
            last--;     
    }
    void heapify(unsigned int position)
    {
        if(position<=last/2)//not leaf
        {
            unsigned int lpos=position*2+1;
            unsigned int rpos=position*2+2;
            T lchild=A.at(lpos);
            T rchild=A.at(rpos);
            if(A.at(position)> lchild && A.at(position)>rchild)
                return;
            if(lchild>rchild)
            {
                T value=A.at(position);
                A.at(position)=lchild;
                A.at(lpos)=value;
                heapify(lpos);
            }
            else
            {
                T value=A.at(position);
                A.at(position)=rchild;
                A.at(rpos)=value;
                heapify(rpos);
            }            
        }
    }
    void changeValue(unsigned int position,T value)
    {
        if(position>last)
        {
            cout<<"Illegal position of the heap\n";
            return;
        }
        T oldvalue=A.at(position);
        A.at(position)=value;
        if(value>oldvalue)
        {
             //if new value > old value : check with parent 
            unsigned int parent=floor(position/2);
            while(A.at(parent)<=value)
            //parent of the current position is less than the value
            {
                T t=A.at(parent);
                A.at(parent)=value;
                A.at(position)=t;
                position=parent;
                parent=floor(position/2);
                if(parent==position)//root: done
                    break;
            }
        }
        //else heapify at position
        else
        {
            heapify(position);
        }        
    }
    void printHeapSort_Ascending()
    {
        if(A.size()==0)
        {
            cout<<"Empty Array\n";
            return;
        }
        if(A.size()==1)
        {
            cout<<A.at(0)<<endl;
            return;
        }
        unsigned int l=last;
        while(last>0)
        {
            T value=A.at(0);
            while(A.at(last)==-999)
                last--;
            A.at(0)=A.at(last);
            A.at(last--)=value;
            heapify(0);
        }
        for(int i=0;i<=l;i++)
        {
            if(A.at(i)!=-999)
                cout<<A.at(i)<<" ";
        }
        cout<<endl;
        buildHeap(A,l);
    }
    //recieves a sorted Array: ascending
    void buildHeap(vector<T> V,unsigned int l)
    {
        int k=l;
        for(int i=0;i<=l;i++)
        {
            A.at(i)=V.at(k--);
        }
    }
};


template <typename T>
struct BinaryTreeNode
{
BinaryTreeNode<T> lchild;
BinaryTreeNode<T> rchild;
T data;
BinaryTreeNode<T> parent;
} ;

template <typename T>
using Hnode= BinaryTreeNode<T>*;

template <typename T>
struct MaxHeap_BinaryTree
{
Hnode start;
void insert(T value)
{
    if(start==NULL)
    {
        start=new BinaryTeeNode<T>;
        start->lchild=NULL;
        start->rchild=NULL;
        start->data=value;
        start->parent=NULL;
        return;
    }
    
}
};