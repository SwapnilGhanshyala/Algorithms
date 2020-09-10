/*First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .*/
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int lengthOfLCS(string s1, string s2, int N, int M)
{
    int LCS[N+1][M+1];
    for(int i=0;i<=N;i++)
        LCS[i][0]=0;
    for(int i=0;i<=M;i++)
        LCS[0][i]=0;

    int result=0;
    for (int i=1; i<=N; i++) 
    { 
        for (int j=1; j<=M; j++) 
        { 
            if (s1.at(i-1) == s2.at(j-1)) 
            { 
                LCS[i][j] = LCS[i-1][j-1] + 1; 
                //result = max(result, LCSuff[i][j]); 
                if(LCS[i][j]>result)
                    result=LCS[i][j];
            } 
            else LCS[i][j] = 0; 
        } 
    } 
    return result; 
}
int lengthOfLCS1(string s1, string s2,int N,int M)
{
    
    int LCS[N+1][M+1];
    for(int i=0;i<=N;i++)
        {
        LCS[i][0]=0;
        }
    for(int i=0;i<=M;i++)
        {
            LCS[0][i]=0;
        }
    
    int maxLength=0,currLength;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(s1.at(i-1)==s2.at(j-1))
            {
                if(i==1 || j==1)//firstMatch
                {
                    LCS[i][j]=1;
                    currLength=1;
                    if(currLength>maxLength)
                        maxLength=currLength;
                    continue;
                }
                
               if(s1.at(i-2)!=s2.at(j-2))//newSubStringFound
               {
                   LCS[i][j]=1;
                   currLength=1;
                   if(currLength>maxLength)
                    maxLength=currLength;
               }
               else
               {
                   LCS[i][j]=LCS[i-1][j-1]+1;
                   currLength++;
                   if(currLength>maxLength)
                    maxLength=currLength;
                    cout<<s1.substr(0,i)<<" "<<i<<endl;
                    cout<<s2.substr(0,j)<<" "<<j<<endl;
               }
            }
            else
            {
                if(LCS[i-1][j]>LCS[i][j-1])
                    {if(LCS[i-1][j]>LCS[i-1][j-1])
                        LCS[i][j]=LCS[i-1][j];
                    else
                        LCS[i][j]=LCS[i-1][j-1];
                    }
                else
                    if(LCS[i][j-1]>LCS[i-1][j-1])
                        LCS[i][j]=LCS[i][j-1];
                    else
                        LCS[i][j]=LCS[i-1][j-1];
            }            
        }
    }
    return maxLength;
}
int main()
{
    int T,N,M;
    cin>>T;
    while(T>=1)
    {
        T--;
        cin>>N;
        cin>>M;
        string str1,str2;
        cin>>str1;
        cin>>str2;
        if(N>100 || N<1 ||M>100 || M<1)
            continue;
        cout<<lengthOfLCS(str1,str2,N,M)<<endl;
    }
    return 0;
}