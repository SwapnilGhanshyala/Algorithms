
//given an array of ascending order (sorted) create a binary tree with minimum height
#include <iostream>
#include <vector>
#include "binaryTree.h"
#include "BSTree.h"
#include <math.h>
using namespace std;




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
    BinaryTree<int> bstree;
    bstree.root=NULL;
    //makeTree(arr,&bstree);
    vector<BinaryTreeNode<int>> nodesArray;
    for(unsigned i=0;i<N;i++)
    {
        cout<<"Enter the value\n";
        int value;
        cin>>value;
        BinaryTreeNode<int> node;
        //cout<<arr[i]<<endl;
        node.data=value;
        node.leftchild=NULL;
        node.rightchild=NULL;
        nodesArray.push_back(node);
    }
    for(unsigned i=0;i<nodesArray.size();i++)
    {
        bstree.nodes.push_back(&nodesArray.at(i));
    }
    //cout<<"The nodes are:\n";
    //printNodesOfTree(bstree);
    cout<<"there are "<<bstree.nodes.size()<<" elements in the tree\n";
    unsigned int mid=floor((bstree.nodes.size()-1)/2);
    bstree.root=bstree.nodes.at(mid);
    //setAsChild(par,child,"left")
    //if(arr.size())
    setAsChild(bstree.root,makeBSTofSortedArray(&bstree,0,mid-1),"left");
    //bstree.root->leftchild=NULL;
    setAsChild(bstree.root,(makeBSTofSortedArray(&bstree,mid+1,bstree.nodes.size()-1)),"right");
    cout<<"printing the tree\n";
    printTree(bstree.root);
    return 1;
}