#include <iostream>

using namespace std;

typedef ExpNode * enode;

struct ExpNode
{
    enode rchild;
    enode lchild;
    char op;
    int data;
};

void printParenthesizedExpression(enode start)
{
    if(start==NULL)
        return;
    if(start->op=='i')//is a leaf/integer
        {cout<<start->data;
        return;}
    if(start->rchild==NULL )
        {
            cout<<"("<<start->op<<printParenthesizedExpression(start->lchild)<<")";
            return;
        }
    else
    {
        if(start->lchild==NULL)
        {
            cout<<"("<<start->op<<printParenthesizedExpression(start->rchild)<<")";
            return;
        }
        cout<<"("<<start->op<<printParenthesizedExpression(start->lchild)<<" "<<start->op<<" "<<start->op<<printParenthesizedExpression(start->rchild)<<")";
    }

}