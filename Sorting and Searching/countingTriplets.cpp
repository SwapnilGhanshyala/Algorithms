#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int countTriplets(vector<int>* A)
{
int i=0,j=0,k=0,counter=0;
long sum=0;
int Asize=A->size();
for(i=0;i<Asize-1;i++)
{
    for(j=i+1;j<Asize;j++)
    {
        sum=A->at(i)+A->at(j);
        for( k=0;k<Asize;k++)
        {
            if(A->at(k)==sum)
                break;
        }
        if(k<Asize)
            counter++;
    }
}
return counter;
}
void printArray(int A[],int Asize)
{
    for(int i=0;i<Asize;i++)
        cout<<A[i]<<" ";;
    cout<<endl;
}
int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}
int binarySearch(int A[],int start,int last,int n)
{
    while(start<=last)
    {
        int mid=(start+last)/2;
        if(A[mid]==n)
            return mid;
        if(A[mid]>n)
            last=mid-1;
        else
            start=mid+1;
    }
    return -1;
}
int countTriplets2(int A[],int Asize)
{
    qsort(A,Asize,sizeof(int),compare);
    //printArray(A,Asize);
    int sum=0,counter=0;
    for(int i=0;i<Asize-1;i++)
    {
            //printArray(A,Asize);

        for(int j=i+1;j<Asize;j++)
        {
            sum=A[i]+A[j];
            //cout<<"Sum is "<<sum<<endl;
            int pos=binarySearch(A,j+1,Asize-1,sum);
            if(pos!=-1)
                counter++;
        }
    }
    if(counter==0)
        return -1;
    return counter;
}
int main()
{
    /*1 <= T <= 100
1 <= A[i] <= 106*/
int T,N,c;
cin>>T;
if(T<0 || T>100)
{
    cerr<<"Illegal Value of T\n";
    return -1;
}
while(T>0)
{
    T--;
    cin>>N;
    /*3 <= N <= 105*/
    
    int n=0;
    int  A[N];
    while(n<N)
    {
        cin>>c;
        if(c<0 || c>pow(10,6))
        {
            cerr<<"Illegal value entered in the array\n";
            return -1;
        }
        A[n]=c;
        n++;
    }
        //printArray(A,N);
        if(N<3 || N>pow(10,5))
        {
            //cout<<"Illegal value of N "<<N<<"\n";
            cout<<-1<<endl;
            continue;
        }
    cout<<countTriplets2(A,N)<<endl;
}
return 0;
}