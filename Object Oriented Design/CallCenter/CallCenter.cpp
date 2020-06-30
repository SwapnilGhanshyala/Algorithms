#include <iostream>
#include <string>
#include <queue>
#include "Employee.h"

using namespace std;

class CallCenter
{
    private:
        HashMapTable EmployeeTable;
        queue<Employee*> freeFresherEmployees;
        queue<Employee*> freeTL;
        queue<Employee*> freePM;
    public:
    //addNewEmployee
    //Etc. modules needed by call center
    Employee* getCallHandler(int callNumber)
    {
        if(freeFresherEmployees.empty())
        {
            if(freeTL.empty())
            {
                if(freePM.empty())
                {
                    cout<<"None of the employees are available";
                    return NULL;
                }
                else
                {
                    Employee* e=freePM.front();
                    freePM.pop();
                    return e;
                }
            }
            else
            {
                Employee* e=freeTL.front();
                freeTL.pop();
                return e;
            }
        }
        else
        {
            Employee* e=freeFresherEmployees.front();
            freeFresherEmployees.pop();
            return e;
        }
    }
};
int main() {
   HashMapTable hash;
   int k, v;
   int c;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>v;
            cout<<"Enter key at which element to be inserted: ";
            cin>>k;
            hash.Insert(k, v);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (hash.SearchKey(k) == -1) {
               cout<<"No element found at key "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.SearchKey(k)<<endl;
            }
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.Remove(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }
   return 0;
}