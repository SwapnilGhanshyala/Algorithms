
#include <iostream>
#include "LL_Func.h"
using namespace std;
/*
void del_dup_nodes(Node<T> *root)
{
    if(root==NULL)
    {
        cerr<<"Empty LL";
        return ;
    }
    if(root->next==NULL)
    {
        return ;
    }
    Node *p=root;
    while(p->next!=NULL)
    {
        cout<<"Stuck here when p->data is "<<p->data<<"\n";
       Node *x=p,*n=p->next;
       while(n!=NULL)
       {
        cout<<"Stuck here when n->data is "<<n->data<<"\n";
           if(n->data==p->data)
               x->next=n->next;
            else
                x=x->next;
           n=n->next;
       }
               cout<<"end stuck here when p->data is "<<p->data<<"\n";
               if(p->next!=NULL)
               p=p->next;
               else
               {
                   break;
               }
               
    }

}
*/
int main()
{
   SinglyLinkList<int> *root=new SinglyLinkList<int>;
  root->createList();
    root->print_LL();
    cout<<"reverse a LL\n";
    root->reverse();
    root->print_LL();
   return 0;
}
