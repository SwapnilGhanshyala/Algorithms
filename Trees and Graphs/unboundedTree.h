//depth(root)==0
#include <iostream>
using namespace std;

template <typename T>
struct UTreeNode
{
T data;
UTreeNode *child;
UTreeNode *rightsibling;
UTreeNode *parent;
};

template <typename T>
bool balancedUTree(UTreeNode<T> *root)
{
return (UTreeMaxDepth(root)-UTreeMinDepth(root)<=1)

}

template <typename T>
int UTreeMaxDepth(UTreeNode<T> *root)
{
    if(root==NULL || root->child==NULL)
    {
        return 0;
    }
    int max=UTreeMaxDepth(root->child);
    UTree *node=root->child;
    while(node->rightsibling!=NULL)
    {
        int d=UTreeMaxDepth(node->rightsibling);
        node=node->rightsibling;
        if(d>max)
        max=d;
    }
    return 1+max;
}

template <typename T>
int UTreeMinDepth(UTreeNode<T> *root)
{
    if(root==NULL || root->child==NULL)
    {
        return 0;
    }
    int min=UTreeMinDepth(root->child);
    UTree *node=root->child;
    while(node->rightsibling!=NULL)
    {
        int d=UTreeMinDepth(node->rightsibling);
        node=node->rightsibling;
        if(d<min)
        min=d;
    }
    return 1+min;
}