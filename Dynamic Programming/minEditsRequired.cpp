/*Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.*/
#include <iostream>
#include <string.h>
using namespace std;
int lengthOfLCS(string s1, string s2,int N,int M)
{
    int LCS[N+1][M+1];
    for(int i=0;i<=N;i++)
        LCS[i][0]=0;
    for(int i=0;i<=M;i++)
        LCS[0][i]=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(s1.at(i-1)==s2.at(j-1))
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else
            {
                if(LCS[i-1][j]>=LCS[i][j-1])
                    LCS[i][j]=LCS[i-1][j];
                else
                    LCS[i][j]=LCS[i][j-1];
            }            
        }
    }
    return LCS[N][M];
}
int minEdits(string s1, string s2,int N,int M)
{
     //why is this code using LCS not working correctly?
     //what is theflaw in the logic?
     /*int lcs=lengthOfLCS(s1,s2,N,M);
     int minL=(N<M)?N:M;
     int maxL=(N+M)-minL;
     
     cout<< (minL-lcs)+(maxL-minL)<<endl; */
     int ME[N+1][M+1];
     for(int i=0;i<=N;i++)
        ME[i][0]=i;
    for(int i=0;i<=M;i++)
        ME[0][i]=i;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(s1.at(i-1)==s2.at(j-1))
                ME[i][j]=ME[i-1][j-1];
            else
            {
                int a=ME[i-1][j-1];
                int b=ME[i-1][j];
                int c=ME[i][j-1];
                if(a<b)
                {
                    if(a<c)
                        ME[i][j]=a+1;
                    else
                        ME[i][j]=c+1;
                }                
                else
                {
                    if(b<c)
                        ME[i][j]=b+1;
                    else
                        ME[i][j]=c+1;
                }
                
            }
        }
    }
    return ME[N][M];
}
int main() {
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
        cout<<minEdits(str1,str2,N,M)<<endl;
    }	return 0;
}