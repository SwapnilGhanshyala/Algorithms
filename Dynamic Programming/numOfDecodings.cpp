#include <iostream>
#include <string>
using namespace std;

int NumOfDecodings(string s,int N)
{

    int D[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            D[i][j]=0;
    }
    for(int i=0;i<N;i++)
        D[i][i]=1;
    for(int i=N-2;i>=0;i--)
    {
        for(int j=i+1;j<N;j++)
        {
            int max=0;
            for(int m=i;m<j;m++)
            {
                int cell=D[i][m]*D[m+1][j];
                if(s.at(m)=='1' ||(s.at(m)=='2' && (s.at(m+1)-'0')<=6) )
                {
                    if(m-1>=i && m+2<j)
                    cell=cell+D[i][m-1]*D[m+2][j];
                    else
                    cell++;
                   /* int flag1=0,flag2=0;
                    if(m!=0)
                        if((s.at(m-1)=='1' ||(s.at(m-1)=='2' && (s.at(m)-'0')<=6)))
                            flag1=1;
                    if(m!=N-2)
                        if((s.at(m+1)=='1' ||(s.at(m+1)=='2' && (s.at(m+2)-'0')<=6)))
                            flag2=1;
                    if(flag1==1 && flag2==1)
                        cell++;*/
                }
                if(max<cell)
                    max=cell;
            }
            D[i][j]=max;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<D[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
        return D[0][N-1];
}
int main() {
/*1<=T<=1000*/
int T,N;
cin>>T;
while(T)
{
    T--;
    cin>>N;
    string s;
    cin>>s;
    if(N<1 || N>40)
    {
        //cout<<"Invalid String "<<s<<endl;
        cout<<0<<endl;
        continue;
    }
    if(N!=s.length())
    {
//cout<<"Invalid String "<<s<<endl;
        cout<<0<<endl;        continue;
    }
    //check for consequtive 0's
    if(s.at(0)=='0')
    {
//cout<<"Invalid String "<<s<<endl;
        cout<<0<<endl;        continue;
    }
    //invalid String if a number >=3 is followed by 0
    //ir of 0 is followed by zero
    int invalidFlag=0;
    for(int i=1;i<N;i++)
    {
        if(s.at(i)=='0' && (s.at(i-1)=='0' || (s.at(i-1)-'0')>=3))
        {
//cout<<"Invalid String "<<s<<endl;
        cout<<0<<endl;            invalidFlag=1;
            break;
        }
        
    }
    if(invalidFlag==1)
        continue;
    cout<<NumOfDecodings(s,N)<<endl;
    
}
return 0;
}