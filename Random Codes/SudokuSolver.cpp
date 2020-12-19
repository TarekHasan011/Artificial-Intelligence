#include<bits/stdc++.h>
#define MAX 9
using namespace std;
int grid[MAX][MAX];

bool In_Row(int row, int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num)
            return true;
    }
    return false;
}

bool In_Column(int column, int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][column]==num)
            return true;
    }
    return false;
}

bool In_Box(int row, int column, int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i+row][j+column]==num)
                return true;
        }
    }
    return false;
}

bool perfect(int row, int column,int num)
{
    return !In_Row(row,num) && !In_Column(column,num) && !In_Box(row- row%3, column- column%3,num);
}

bool sudoku_solve()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(grid[i][j]==0)
            {
                int choice=1;
                for(;choice<=9;choice++)
                {
                    if(perfect(i,j,choice))
                    {
                        grid[i][j]=choice;
                        if(sudoku_solve())
                            break;
                        grid[i][j]=0;
                    }
                }
                if(choice>9)
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan

    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            cin >> grid[i][j];
    if(sudoku_solve())
    {
        for(int i=0;i<MAX;i++)
        {
            for(int j=0;j<MAX;j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "No Solution Exist\n";
}

/*
input format:

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

*/
