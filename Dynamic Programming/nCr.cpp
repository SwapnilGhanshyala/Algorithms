#include <iostream>
#include <math.h>
using namespace std;

long NCR1(int N,int R)
{
    if(N<R)
    return 0;
    if(N==R)
    return 1;
    long C[N][R];
    for(int i=0;i<N;i++)
    {
        C[i][0]=i+1;
        if(i<R)
            C[i][i]=1;
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<i && j<R;j++)
        {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%1000000007;
            //cout<<"for "<<i<<" , "<<j<<endl;
        }
    }
    return C[N-1][R-1];
}
//still in work: reducing the space complexity
 int NCR(int N,int R)
{
    if(N<R)
    return 0;
    if(N==R)
    return 1;
    int C[R+1];
    for( int i=1;i<=N;i++)
    {
        for(int j=2;j<=R && j<i;j++)
        {
            C[j]=(C[j]%1000000007+C[j-1]%1000000007)%1000000007;
        }
        C[1]=i;
        if(i<=R)
            {C[i]=1;}
    }
    return C[R];
}
int main()
{
    int T,N,R,c;
    cin>>T;
    while(T>0)
    {
        T--;
        /*1 <= T <= 50
        1 <= n <= 103
        1 <= r <= 800*/
        cin>>N;
        cin>>R;
        if(N<0 || N>pow(10,3))
            continue;
        if(R<0 || R>800)
            continue;

        cout<<NCR1(N,R)<<endl;
    }
    return 0;
}