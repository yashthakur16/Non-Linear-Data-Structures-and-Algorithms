#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& sudoku,int val,int row,int col)
{
    for(int i=0;i<sudoku.size();i++)
    {
        if(sudoku[row][i]==val)
        {
            return false;
        }
        if(sudoku[i][col]==val)
        {
            return false;
        }
        if(sudoku[(3*(row/3))+i/3][(3*(col/3))+i%3]==val)
        {
            return false;
        }
    }

    return true;
}



bool solve(vector<vector<int>>& sudoku)
{
    int n=sudoku[0].size();

    for(int row=0;row<n;row++ )
    {
        for(int col=0;col<n;col++)
        {
            if(sudoku[row][col]==0)
            {
                for(int val=1;val<=9;val++)
                {
                    if(isSafe(sudoku,val,row,col))
                    {
                        sudoku[row][col]=val;
                        if(solve(sudoku))
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
    return ;
}

int main() {
    vector<vector<int>> sudoku = {
        {0, 0, 0, 4, 0, 3, 8, 0, 0},
        {5, 0, 0, 0, 9, 0, 0, 0, 0},
        {0, 8, 6, 0, 0, 0, 0, 0, 7},
        {0, 0, 5, 2, 0, 0, 0, 8, 4},
        {0, 2, 1, 0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 7, 0, 9},
        {1, 5, 0, 7, 0, 0, 9, 0, 8},
        {4, 9, 0, 0, 1, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 1}
    };

    solveSudoku(sudoku);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
