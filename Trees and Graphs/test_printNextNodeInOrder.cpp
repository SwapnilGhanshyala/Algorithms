#include <iostream>
#include "BSTree.h"
#include <math.h>

using namespace std;
int main()
{
    cout<<"Enter the number of elements you want in the tree\n";
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
        node.parent=NULL;
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
    printTree(bstree.root);
    cout<<"Enter the index of the node's index, whose next you want to find\n";
    unsigned int index;
    cin>>index;
    printNextNodeInOrder(bstree.nodes.at(index));
    return 0;
}

