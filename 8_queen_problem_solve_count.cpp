#include<bits/stdc++.h>
#define SIZE 8
using namespace std;
char board[SIZE][SIZE];
bool isSafe(int r, int c)
{
    for(int i=0;i<SIZE;i++)
    {
        if(board[r][i]=='Q')
            return false;
    }
    for(int i=0;i<SIZE;i++)
    {
        if(board[i][c]=='Q')
            return false;
    }
    for(int i=r,j=c;i<SIZE && j<SIZE;i++,j++)
    {
        if(board[i][j]=='Q')
            return false;
    }
    for(int i=r,j=c;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
            return false;
    }
    for(int i=r,j=c;i<SIZE && j>=0;i++,j--)
    {
        if(board[i][j]=='Q')
            return false;
    }
    for(int i=r,j=c;i>=0 && j<SIZE;i--,j++)
    {
        if(board[i][j]=='Q')
            return false;
    }
    return true;
}
int solve(int row)
{
    if(row==SIZE) return true;

    int counter = 0;
    for(int i=0;i<SIZE;i++)
    {
        if(isSafe(row,i))
        {
            board[row][i]='Q';
            counter += solve(row+1);
            board[row][i]='.';
        }
    }
    return counter;
}
int main()
{
    memset(board,'.',sizeof(board));
    cout << solve(0) << endl;
    return 0;
}

