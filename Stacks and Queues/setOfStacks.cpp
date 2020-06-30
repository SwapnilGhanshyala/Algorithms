#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct oneStack
{
    stack<int> st;
    oneStack *prev;
};
class setOfStacks
{
vector<oneStack*> stackSet;
oneStack *topStack;
int LIMIT;
public:
void setofStacks()
{
    topStack=NULL;
}
void setLIMIT(int limit)
{
    LIMIT=limit;
}
void push(int num)
{
    //check if the stack is full 
    //if full create a new stack and push it tot he setof stack
    if(stackSet.empty() || topStack->st.size()==LIMIT)
    {
        cout<<"Need to create new stack \n";
        oneStack new_stack;
        new_stack.prev=NULL;
        new_stack.st.push(num);
        cout<<"Successfully created stack and pushed to it\n";
        pushStack(&new_stack);
        return ;        
    }
    (topStack->st).push(num);
}
void pop()
{
    if(stackSet.empty() || topStack==NULL)
    {
        cerr<<"Empty SetOfStacks\n";
        return ;
    }
    if((topStack->st).empty())
    {
        popStack();
        pop();
    }
    (topStack->st).pop();
}
void popAt(int index)
{
    if(stackSet.empty())
    {
        cerr<<"Set of stacks is empty\n";
        return;
    }
    if(stackSet.size()<=index)
    {
        cerr<<"Invalid index";
        return;
    }
    oneStack *indexedStack=stackSet.at(index);
    if(indexedStack->st.empty())//if the indexed stack is empty
    {
        cerr<<"Indexed Stack is empty\n";
        return;
    }
    ((stackSet.at(index))->st).pop();
}
private:
void pushStack(oneStack *newStack)
{
    cout<<"Pushing into a newStack\n";
    if(topStack==NULL)
    {
        topStack=newStack;
    return;}
newStack->prev=topStack;
topStack=newStack;
}
oneStack* popStack()
{
    if(stackSet.empty())
    {
        cerr<<"Empty set";
        return NULL;
    }
    oneStack *top=topStack;
    topStack=topStack->prev;
    top->prev=NULL;
    return top;
}

};
