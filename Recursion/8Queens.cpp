/*Write an algorithm to print all ways of arranging eight queens on a chess board so
that none of them share the same row, column or diagonal.*/

#include <iostream>
#include <vector>

using namespace std;
class EightQueens
{
private :
int chessBoard[8][8];
public :
EightQueens()
{
    for(int i=0;i<8;i++)
    {
         for(int j=0;j<8;j++)
        {
            chessBoard[i][j]=0;
        }
    }
}
bool isRowOccupied(int rowNum)
{
    for(int i=0;i<8;i++)
    {
        if(chessBoard[rowNum][i]==1)
            return true;
    }
    return false;
}
bool isColOccupied(int ColNum)
{
    for(int i=0;i<8;i++)
    {
        if(chessBoard[i][ColNum]==1)
            return true;
    }
    return false;
}
bool isDiagOccupied(int r, int c)
{
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
    {
        if(chessBoard[i][j]==1)
            return true;
    }
    for(int i=r+1,j=c-1;i<8 && j>=0;i++,j--)
    {
        if(chessBoard[i][j]==1)
            return true;
    }  
    return false;
}
int CalcNumOfPlacements( int col)
{
    cout<<"for column "<<col<<endl;
    int num_ways=0;
    if(col==7)
    {
        for(int i=0;i<8;i++)
        {
            if(!isRowOccupied(i) && !isDiagOccupied(i,7))
            {
                num_ways++;
            }
        }
        return num_ways;
    }
    for(int i=0;i<8;i++)
    {
        if(!isRowOccupied(i) && !isDiagOccupied(i,col))
            {
                chessBoard[i][col]=1;
                num_ways+=CalcNumOfPlacements(col+1);
                chessBoard[i][col]=0;
            }       
    }
    return num_ways;
}
};
int main()
{
    EightQueens e;
    int n=e.CalcNumOfPlacements(0);
    cout<<n;
}