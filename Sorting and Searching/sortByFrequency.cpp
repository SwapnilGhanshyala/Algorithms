#include <iostream>
using namespace std;
int freq[60];
int compare(const void *a,const void *b)
{
    const int* x = (int*) a;
	const int* y = (int*) b;
	
	if(freq[*x]>freq[*y])
	    return -1;
	if(freq[*x]<freq[*y])
	    return 1;
	if(*x<*y)
	    return -1;
	if(*x>*y)
	    return 1;
	return 0;
}
void sortByFrequency(int A[],int Asize)
{
    for(int i=0;i<60;i++)
        freq[i]=0;
    for(int i=0;i<Asize;i++)
        freq[A[i]]++;
    qsort(A,Asize,sizeof(int),compare);
    for(int i=0;i<Asize;i++)
        cout<<A[i]<<" ";
    cout<<endl;
        
}
int main() {
/*1 ≤ T ≤ 70
30 ≤ N ≤ 130
1 ≤ Ai ≤ 60 */
int T,N,a;
cin>>T;
if(T<1 || T>70)
    cerr<<"Illegal Value of T\n";
while(T>0)
{
    T--;
    cin>>N;
    int n=0;
    int A[N];
    while(n<N)
    {
        cin>>a;
        
        A[n]=a;
        n++;
    }
    
    sortByFrequency(A,N);
}return 0;
}