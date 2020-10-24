#include <iostream>
#include "LL_Func.h"
using namespace std;
int main()
{
   SinglyLinkList<int> *list1=new SinglyLinkList<int>;
   SinglyLinkList<int> *list2=new SinglyLinkList<int>;
  list1->createList();
    list1->print_LL();
    list2->createList();
    list2->print_LL();
    list1->merge(list2);
    list1->print_LL();
   return 0;
}