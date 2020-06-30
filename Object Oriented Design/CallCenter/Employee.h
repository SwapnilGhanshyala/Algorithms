#include <iostream>
#include <string>
//#include<cstdlib>
//#include<cstdio>
using namespace std;

enum EType {fresher,TL,PM,NA};
enum Status {Busy, Available};
 class Employee
{
    private :
    int EID;
    string EName;
    EType Designation;
    int HID;
    Status status; 

    public:
    Employee(string name,int id, EType desig, int headID, Status s)
    {
        EName=name;
        EID=id;
        Designation=desig;
        HID=headID;
        status=s;
    }
    Employee()
    {
        EName="";
        EID=-999;
        Designation=NA;
        HID=-999;
        status=Busy;
    }
    int getHeadID()
    {
        return HID;
    }
    void setHeadID(int new_head)
    {
        HID=new_head;
    }
    string getEName()
    {
        return EName;
    }
    int getEID()
    {
        return EID;
    }
    void setEName(string name)
    {
        EName=name;
    }
    void setEID(int id)
    {
        EID=id;
    }
    EType getDesignation()
    {
        return Designation;
    }
    void setDesignation(EType new_Designation)
    {
        Designation=new_Designation;
    }
  
};


class HashTableEntry{
   public:
      int k;
      Employee* emp=NULL;
      HashTableEntry(int k, Employee *emp) {
         this->k= k;
         this->emp = emp;
      }
};
class HashMapTable {
   private:
      HashTableEntry **t;
      int TableSize ;
   public:
      HashMapTable(int size) {
          TableSize=size;
         t = new HashTableEntry * [TableSize];
         for (int i = 0; i< TableSize; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int k) {
         return k % TableSize;
      }
      void Insert(int k, Employee* employee) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableEntry(k, employee);
      }
      Employee* SearchKey(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return NULL;
         else
            return t[h]->emp;
      }
      void Remove(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL) {
            if (t[h]->k == k)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         } else {
            delete t[h];
         }
         cout<<"Element Deleted"<<endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < TableSize; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
      }
};
