#include <iostream>
#include <string.h>
using namespace std;

int main() {

int T;
cin>>T;
while(T)
{
T--;
string s;
cin>>s;
int A[s.size()];
for(int i=0;i<s.size();i++)
    A[i]=0;
int sq=0,cc=0,cb=0,flag=0;
for(unsigned int i=0;i<s.size();i++)
{
    if(s.at(i)=='(')
        cc++;
    else
    {
        if(s.at(i)=='[')
        sq++;
        else
        {
            if(s.at(i)=='{')
                cb++;
            else
            {   
                if(s.at(i)==')')
                {
                    cc--;
                    for(int j=i-1;j>=0;j--)
                    {
                        if(s.at(j)=='(' && A[j]==0)//this is the parenthesis we closed for
                        {
                            A[j]=1;
                            break;
                        }
                        if((s.at(j)=='[' || s.at(j)=='{') && A[j]==0)//this was open instead of a cc
                        {flag=1;break;}
                    } 
                    if(flag==1)
                        break;
                }
                else
                {
                    if(s.at(i)==']')
                    {
                        sq--;
                        for(int j=i-1;j>=0;j--)
                        {
                        if(s.at(j)=='[' && A[j]==0)//this is the parenthesis we closed for
                            {A[j]=1;
                                break;
                            }
                        if((s.at(j)=='(' || s.at(j)=='{') && A[j]==0)//this was open instead of a cc
                        {flag=1;break;}
                        }
                        if(flag==1)
                        break;
                    }
                    else
                    {
                        if(s.at(i)=='}')
                        {
                            cb--;
                            for(int j=i-1;j>=0;j--)
                            {
                            if(s.at(j)=='{' && A[j]==0)//this is the parenthesis we closed for
                                {A[j]=1;break;}
                            if((s.at(j)=='[' || s.at(j)=='(') && A[j]==0)//this was open instead of a cc
                            {flag=1;break;}
                            }
                        }
                        if(flag==1)
                            break;
                    }                                        
                }
            }
        }
    }
}
    if(flag==1 || sq!=0 || cc!=0 || cb!=0)
        cout<<"not balanced"<<endl;
    else
        {
            cout<<"balanced"<<endl;
        }
        
}//T loop
return 0;
}