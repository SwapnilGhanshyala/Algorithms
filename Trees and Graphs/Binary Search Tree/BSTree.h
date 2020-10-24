
#include "../BinaryTrees/binaryTree.h"
#include <math.h>
//create a BST recursively
typedef BinarySearchTreeNode * BSTNode;

struct BinarySearchTreeNode
{
BSTNode parent;
BSTNode leftchild,rightchild;
int data;
void insert(int value)
{
    if(value>data)
        if(rightchild)
            rightchild->insert(value);
        else
        {
            rightchild= new BinarySearchTreeNode;
            rightchild->data=value;
            rightchild->rightchild=NULL;
            rightchild->leftchild=NULL;
            rightchild->parent=this;
        }    
    else
    {   
        if(leftchild)
         leftchild->insert(value);
         else
        {
            leftchild= new BinarySearchTreeNode;
            leftchild->data=value;
            leftchild->rightchild=NULL;
            leftchild->leftchild=NULL;
            leftchild->parent=this;
        }
    }   
}
BSTNode search(int value)
{
    if(data==value)
        return this;
    if(data>value)
        return leftchild->search(value);
    return rightchild->search(value);
}
};
struct BinarySearchTree
{
BSTNode start;
int size;
BSTNode searchValue(int value)
{
    if(start==NULL)
        return NULL;
    if(start->data==value)
        return start;
    if(start->data>value)
        return start->leftchild->search(value);
    return start->rightchild->search(value);
}
void  insert(int value)
{
    if(start==NULL)//empty tree
    {
        start=new BinarySearchTreeNode;
        start->data=value;
        start->leftchild=start->rightchild=NULL;
        start->parent=NULL;
        return;
    }
    start->insert(value);
}

//deleting an Element and replacing with inorderSuccesor/Predeccessor if needed
void deleteKey(int value)
{
    if(start==NULL)//empty tree
        return;
    //if single node tree
    if(start->leftchild==NULL && start->righchild==NULL)
    {    if(start->data==value)
            start=NULL;
        return;
    }
    BSTNode found=searchValue(value);
    if (found==NULL)
        return;
    BSTNode par=found->parent;
    bool isaRchild=(par->rightchild==found)?true:false;
    //if found isa leaf
    if(found->leftchild==NULL && found->rightChild==NULL)
    {
        if(isaRchild)
            par->rightchild=NULL;
        else
            par->leftchild=NULL;
        return;
    }
    if(found->rightchild==NULL)
    {
        if(found==start)
            {found->leftchild->parent=NULL;
            start=found->leftchild;
            return;}
        else
        {
            if(isaRchild)
                par->righchild=found->leftchild;
            else
                par->leftchild=found->leftchild;
            found->leftchild->parent=par;
        }        
    }
    else
    {
        BSTNode succ=found->righchild;
        while(succ->leftchild)
            succ=succ->leftchild;
        if(isaRchild)
            par->rightchild=succ;
        else
            par->leftchild=succ;
        if(succ!=found->rightchild)
        {
            succ->parent->leftchild=succ->rightchild;
            if(succ->rightchild!=NULL)
                succ->rightchild->parent=succ->parent;
            succ->rightchild=found->rightchild;
            found->rightchild->parent=succ;
        }
        succ->leftchild=found->leftchild;
        found->leftchild->parent=succ;
        succ->parent=found->parent;
    }
    
    found->leftchild=NULL;
    found->rightchild=NULL;
    found->parent=NULL;
    return;
}
};
template <typename T>
BinaryTreeNode<T>* makeBSTofSortedArray(BinaryTree<T>* bstree,int start,int end)
{
    if(start>end)
        return NULL;
    //BinaryTreeNode<int> node;
    //bstree->nodes.at((start+end)/2);
    if(start==end)
    {
        bstree->nodes.at((start+end)/2)->leftchild=NULL;
        bstree->nodes.at((start+end)/2)->rightchild=NULL;
        return bstree->nodes.at((start+end)/2);
    }
    unsigned int mid=floor((start+end)/2);
    setAsChild(bstree->nodes.at((start+end)/2),makeBSTofSortedArray(bstree,start,mid-1),"left");
    setAsChild(bstree->nodes.at((start+end)/2),makeBSTofSortedArray(bstree,mid+1,end),"right");
    return bstree->nodes.at((start+end)/2);
}
/*Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a given node in
a binary search tree where each node has a link to its parent.*/
/*Solution:traverse the node */
template <typename T>
void printNextNodeInOrder(BinaryTreeNode<T> *node)
{
    if(node->rightchild==NULL)
    {
        BinaryTreeNode<T>* p=node->parent;
        if(node==p->leftchild)
        {
            cout<<p->data<<endl;
            return;
        }
        if(p->parent==NULL)
        {
            cout<<"No Next\n";
                return;
        }
        while(p==p->parent->rightchild)
        {
            p=p->parent;
            if(p==NULL)
            {
                cout<<"No Next\n";
                return;
            }
        }
        cout<<p->parent->data<<endl;
        return;
    }
    else
    {
        BinaryTreeNode<T>* p=node->rightchild;
        while(p->leftchild!=NULL || p->rightchild!=NULL)
        {
            if(p->leftchild!=NULL)
            {
                p=p->leftchild;
                continue;
            }
            if(p->rightchild!=NULL)
            {
                p=p->rightchild;
                continue;
            }
        }
        cout<<p->data<<endl;
            return;
    }
}
