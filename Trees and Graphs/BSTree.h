
#include "binaryTree.h"
#include <math.h>
//create a BST recursively
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
