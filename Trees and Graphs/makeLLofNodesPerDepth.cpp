/*Given a binary search tree, design an algorithm which creates a linked list of all the
nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).*/
#include <iostream>
#include "C:\Users\swapn\Documents\VSprojects\LinkedList\LL_Func.h"
#include <vector>
#include <queue>
#include "binaryTree.h"

//returns Array of LL, suxh that each LL represents a level of nodes in the given tree
template <typename T>
vector<Node<T>*> make_linkedList(BinaryTree<T> *tree)
{
    vector<Node<T>*> array_linkedList; 
    
    if(tree==NULL)
        return array_linkedList;

    Node<T> *node=new Node<T>;
    node->data=tree->root->data;
    node->next=NULL;
    array_linkedList.push_back(node);
    
    if(tree->nodes.size()==1)
        return array_linkedList; 

    queue<BinaryTreeNode<T>* > q;
    queue<int> index;
    q.push(tree->root->leftchild);
    index.push(1);
    q.push(tree->root->rightchild);
    index.push(1);

    while(!q.empty())
    {
        BinaryTreeNode<T>* n=q.front();
        q.pop();
        unsigned ind=index.front();
        index.pop();
        if(n==NULL)
            continue;
        q.push(n->leftchild);
        index.push(ind+1);
        q.push(n->rightchild);
        index.push(ind+1);
        Node<T>* ll_node=new Node<T>;
        ll_node->data=n->data;
        ll_node->next=NULL;
        
        if(ind>=array_linkedList.size())
            array_linkedList.push_back(ll_node);
        else
        {
            Node<T>* p=array_linkedList.at(ind);
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=ll_node;
        }
        
    }
    return array_linkedList;
}

int main()
{
    cout<<"Enter the number of elements you want in the tree\n\n";
    int N;
    cin>>N;
    if(N<=0 || N>100)
    {
        cerr<<"Illegal length, please retry\n";
        return -1;
    }
    vector<int> arr;
    for(unsigned i=0;i<N;i++)
    {
        cout<<"Enter the value\n";
        int value;
        cin>>value;
       arr.push_back(value);
    }
    BinaryTree<int> tree=makeTreeOfArray(arr);
    
    cout<<"Printing the tree\n";
    printTree(tree.root);
    cout<<"Making the LinkedList\n";
    vector<Node<int>*> array_LinkedList=make_linkedList(&tree);
    cout<<"Printing the LinkedList\n";
    for(unsigned i=0;i<array_LinkedList.size();i++)
    {
        print_LL(array_LinkedList.at(i));
        cout<<"\n";
    }
    return 0;
}

