#include "heap.h"
using namespace std;
int main()
{
MaxHeap<int> heap;
    int n;
for(int i=0;i<5;i++)
{
    cout<<"Enter the value you want in the heap\n";
    cin>>n;
    heap.insert(n);
}
heap.printHeap();
/*
unsigned int position ;

cout<<"Enter the position you want to delete \n";
cin>>position;
heap.deleteValue(position);

cout<<"Enter the position you want to change value for \n";
cin>>position;
cout<<"Enter the new Value\n";
cin>>n;
heap.changeValue(position,n);
*/
heap.printHeap();
heap.printHeapSort_Ascending();
heap.printHeap();
}