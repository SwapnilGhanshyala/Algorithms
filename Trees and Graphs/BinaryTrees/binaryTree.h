//depth(root)==0
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


template <typename T>
struct BinaryTreeNode
{
T data;
BinaryTreeNode * rightchild;
BinaryTreeNode * leftchild;
BinaryTreeNode * parent;
};


//use this structure for dense trees
template <typename T>
struct BinaryTree
{
    BinaryTreeNode<T> *root; 
    vector<BinaryTreeNode<T> *> nodes;
};

template <typename T>
bool balancedBinaryTree(BinaryTreeNode<T> *root)
{
return (BinaryTreeMaxDepth(root)-BinaryTreeMinDepth(root)<=1);
}

template <typename T>
//function to evaluate height of a Binary Tree
int BinaryTreeMaxDepth(BinaryTreeNode<T> *root)
{
    if(root==NULL || (root->rightchild==NULL && root->leftchild==NULL))
    {
        return 0;
    }
    return 1+max(BinaryTreeMaxDepth(root->rightchild), BinaryTreeMaxDepth(root->leftchild));
}

template <typename T>
int BinaryTreeMinDepth(BinaryTreeNode<T> *root)
{
    if(root==NULL || (root->rightchild==NULL && root->leftchild==NULL))
    {
        return 0;
    }
        return 1+min(BinaryTreeMinDepth(root->rightchild), BinaryTreeMinDepth(root->leftchild));

}
template <typename T>
int isBalancedAtNode(BinaryTreeNode<T> *node)
{
    //if leftChild is imbalanced return -1
    if(node->leftchild!=NULL && !balancedBinaryTree(node->leftchild))
    return -1;
    //if rightchild is imbalanced return 1
    if(node->rightchild!=NULL && !balancedBinaryTree(node->rightchild))
    return 1;
    //else 0
return 0;
}
//set as child
template <typename T>
void setAsChild(BinaryTreeNode<T>* parent,BinaryTreeNode<T>* child,string child_dir)
{
    if(parent==NULL)
    {
        cerr<<"Illegal parent";
        return;
    } 
    if (child_dir.compare("left")!=0 && child_dir.compare("right")!=0)
    {
        cerr<<"Illegal child direction";
        return;
    }
    if(child!=NULL)
        child->parent=parent;

    if(child_dir.compare("left")==0)
        parent->leftchild=child;
    else
        parent->rightchild=child;
}


// write a function to print breadth first traversal of the tree
//tree has no cycle so no need to mark visited and unvisited nodes
template <typename T>
void printTree(BinaryTreeNode<T>* root)
{
    if(root==NULL)
    {
        cout<<"Empty tree\n";
        return;
    }
    cout<<root->data<<"\n";
    if(root->leftchild==NULL && root->rightchild==NULL)
    {
        return;
    }
    queue<BinaryTreeNode<T>*> q;
    if(root->leftchild!=NULL)
    q.push(root->leftchild);
    if(root->rightchild!=NULL)
    q.push(root->rightchild);
    while(!q.empty())
    {
        BinaryTreeNode<T>* node=q.front();
        q.pop();
        if(node==NULL)
        continue;
        cout<<node->data<<"\n";
        if(node->leftchild!=NULL)
        q.push(node->leftchild);
        if(node->rightchild!=NULL)
        q.push(node->rightchild);    
    }
}
template <typename T>
void printNodesOfTree(BinaryTree<T> tree)
{
    if((&tree)==NULL)
    {
        cerr<<"Invalid tree to print";
        return;
    }
    for(unsigned i=0;i<tree.nodes.size();i++)
    {
        cout<<tree.nodes.at(i)->data<<endl;
    }
}

//function to make a tree from a given array. 
//parent at i-1 and child at 2i-1 and 2i
template <typename T>
BinaryTree<T> makeTreeOfArray(vector<T> arr)
{
    BinaryTree<T> tree;
    tree.root=NULL;
    if(arr.size()==0)
        return tree;
    for(unsigned int i=0;i<arr.size();i++)
    {
        BinaryTreeNode<T>* node=new BinaryTreeNode<T>;
        node->data=arr.at(i);
        node->leftchild=NULL;
        node->rightchild=NULL;
        tree.nodes.push_back(node);
    }
    cout<<"Setting children for "<< tree.nodes.size() <<" nodes\n";
    for(unsigned i=1;i<=tree.nodes.size()/2;i++)
    {
        cout<<"setting leftchild\n";
        if((2*i-1)<tree.nodes.size())
        //void setAsChild(BinaryTreeNode<T>* parent,BinaryTreeNode<T>* child,string child_dir)
            setAsChild(tree.nodes.at(i-1),tree.nodes.at(2*i-1),"left");
            //tree.nodes.at(i-1)->leftchild=tree.nodes.at(2*i-1);
        cout<<"Setting rightchild";
        if((2*i)<tree.nodes.size())
            setAsChild(tree.nodes.at(i-1),tree.nodes.at(2*i),"right");
        cout<<"Done for "<<i-1<<"th node\n";
    }
    tree.root=tree.nodes.at(0);
    return tree;
}
//print InorderTraversal
template <typename T>
void printInOrderTraversal(BinaryTreeNode<T> *root)
{
    if(root->leftchild!=NULL)
        printInOrderTraversal(root->leftchild);
    cout<<root->data<<" ";
    if(root->rightchild!=NULL)
        printInOrderTraversal(root->rightchild);    
}

//find the first common ancestor of 2 nodes in binary tree
//case1 where node has a pointer to parent
template <typename T>
BinaryTreeNode<T>* getFirstCommonAncestorWithParentPointer(BinaryTreeNode<T>* node1, BinaryTreeNode<T>* node2,BinaryTree<T>* tree)
{
    int depth1=0,depth2=0;
    BinaryTreeNode<T>* n=node1->parent;
    while(n!=NULL)
    {
        n=n->parent;
        depth1++;
    }
    n=node2->parent;
    while(n!=NULL)
    {
        n=n->parent;
        depth2++;
    }
    while(depth1>depth2)
    {
        node1=node1->parent;
            depth1--;
    }
    while(depth2>depth1)
    {
        node2=node2->parent;
        depth2--;
    }
    while(true)
    {
        if(node1==node2)
            return node1;
        node1=node1->parent;
        node2=node2->parent;
    }
}
//case2 where node has no parent pointer
template <typename T>
BinaryTreeNode<T>* getFirstCommonAncestor(BinaryTreeNode<T>* node1,BinaryTreeNode<T>* node2,BinaryTree<T>* tree)
{
    if(node1==NULL || node2==NULL || tree==NULL)
    {
        cerr<<"Either node1 or node2 or the tree is NULL, Invalid Input\n";
        return NULL;
    }
    if(node1==node2)
    {
        cout<<"The given nodes are same \n";
        return root;
    }
    if(node1==root || node2==root)
        return root;
    BinaryTreeNode<T>* p=root;
    while(p!=NULL)
    {
        bool lchild1=covers(p->leftchild,node1);
        bool lchild2=covers(p->leftchild,node2);
        bool rchild1=covers(p->rightchild,node1);
        bool rchild2=covers(p->rightchild,node2);
        if(lchild1==false && lchild2==false && rchild1==false && rchild2==false)
        {
            cerr<<"either of the nodes does not belong to the tree";
            return NULL;
        }
        if((lchild1 && rchild2) || (lchild2 && rchild1))
            return p;
        if(lchild1 && lchild2)
            p->p->leftchild;
        else
            p=p->rightchild;
    }
}

//check if the root covers has a given node
//covers: if the tree with given root has this node 
//using depth firstSearch for this
template <typename T>
bool covers(BinaryTreeNode<T>* root, BinaryTreeNode<T>* node)
{
    if(root==NULL || node==NULL)
    {
        cout<<"Neither root nor node can be NULL to find the cover/n";
        return false;
    }

    if(root==node)
        return true;
    if(root->leftchild==NULL && root->rightchild==NULL)
    {
        cout<<"Invalid tree, root has no children\n";
        return false;
    }
    stack<BinarytreeNode<T>*> s;
    if(root->leftchild!=NULL)
        s.push(root->leftchild);
    if(root->rightchild!=NULL)
        s.push(root->rightchild);
    while(!s.empty())
    {
        if(s.top()==node)
            return true;
        BinaryTreeNode<T>* n=s.top();
        s.pop();
        if(n->leftchild!=NULL)
            s.push(n->leftchild);
        if(n->rightchild!=NULL)
            s.push(n->rightchild);
    
    }
    return false;
}
//compare if 2 trees are identical or not
template <typename T>
bool isIdentical(BinaryTreeNode<T> * root1,BinaryTreeNode<T>* root2)
{
    if(root1==NULL || root2==NULL)
    {
        cout<<"Either one or both the roots are NULL";
        return false;
    }
    stack<BinaryTreeNode<T>*> nodes1;
    stack<BinaryTreeNode<T>*> nodes2;
    nodes1.push(root1);
    nodes2.push(root2);
    while(!nodes1.empty() && !nodes2.empty())
    {
        BinaryTreeNode<T>* n1=nodes1.top();
        BinaryTreeNode<T>* n2=nodes2.top();
        nodes1.pop();
        nodes2.pop();
        if(n1.data==n2.data)
        {
            //if n1 has a leftchild and n2 has a left child : push
            if(n1->leftchild!=NULL)
            {
                if(n2->leftchild!=NULL)
                {
                    nodes1.push(n1->leftchild);
                    nodes2.push(n2->leftchild);
                }
                else
                    return false;
            }
            else
            {
                if(n2->leftchild!=NULL)
                    return false;
            }
            //if n1 has a leftchild and n2 does not, return false
            //if n1 does have a leftchild and n2 does: return false
            //if bot do not have a leftchild : do nothing , goto rightchild
            if(n1->righchild!=NULL)
            {
                if(n2->rightchild!=NULL)
                {
                    nodes1.push(n1->rightchild);
                    nodes2.push(n2->rightchild);
                }
                else
                    return false;
            }
            else
            {
                if(n2->rightchild!=NULL)
                    return false;
            }
        }
        else
        {
            return false;
        }
        
    }
    if(!nodes1.empty() || !nodes2.empty())
        return false;
    else
        return true;   
}
//check if tree2 is a subtree if tree1: has the same tree structure and data
template <typename T>
bool isSubTree(BinaryTree<T>* tree1,BinaryTree<T>*  tree2)
{
    if(tree1==NULL)
    {
        cout<<"the tree is null\n";
        return false;
    }
    if(tree2==NULL)
    {
        cout<<"The child tree is null\n";
        return true;
    }
    if(tree1->root->leftchild==NULL && tree1->root->rightchild==NULL)
        return false;
    stack<BinaryTreeNode<T>*> s;
    s.push(tree1->root);
    while(!s.empty())
    {
        BinaryTreeNode<T>* n1=s.top();
        s.pop();
        if(n1->data==root2->data)
        {
            if(isIdentical(n1,root2))
                return true;
        }
        if(n1->leftchild!=NULL)
            s.push(n1->leftchild);
        if(n1->rightchild!=NULL)
            s.push(n1->rightchild);
    }
    return false;
}
/*
//TODO: find depth of the given node in a tree
template <typename T>
int getNodeDepth(BinaryTree<T>* tree, BinaryTreeNode<T> node)
{

}
*/

//TODO: print post and preordetr traversal
/*
template <typename T>
void balanceBSTAfterNewNode(BinaryTreeNode<T> *node)
{
    if(node==NULL)
        return;
        BinaryTreeNode<T> *p=node;
    while(p!=NULL)
    {
        int balance=isBalancedAtNode(p);
        if(balance==-1)
        {
            //leftchild is imbalanced
            break;
        }
        if(balance==1)
        {
            //rightchild is imbalanced
            break;
        }
        p=p->parent;
    }
}
*/
/*
//given an array sorted in ascending order , construct a binary tree with minimun depth
//algo returns a balanced binary search tree
template <typename T>
BinaryTreeNode<T>* binaryTreeOfMinimumDepth(vector<T> arr)
{
BinaryTreeNode<T>* root;
if(arr.empty())
return NULL;
root->data=arr.at(0);
root->leftchild=NULL;
root->rightchild=NULL;
root->parent=NULL;
if()
BinaryTreeNode<T> *p;
for(unsigned i=0;i<arr.size();i++)
{
    BinaryTreeNode<T> * node;
    node->data=arr.at(i);
    p=root;
    while(p->leftchild!=NULL || p->rightchild!=NULL)
    {
        if(p->data<node->data)
        {
            if(p->rightchild==NULL)
                {
                    p->rightchild=node;
                    node->parent=p;
                    balanceBSTAfterNewNode(p->parent);
                }
            else
            {
                p=p->rightchild;
            }
            
        }
        else
        {
            if(p->leftchild==NULL)
                {
                    p->leftchild=node;
                    node->parent=p;
                }
            else
                p=p->leftchild;
        }
        
    }
    
}
return root;
}
*/
