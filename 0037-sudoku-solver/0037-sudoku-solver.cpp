#include <vector>
#include <iostream>
using namespace std;

class Solution {

public:
    bool rowC(vector<vector<char>>& board, int row, char ch) {

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) {
                return false;
            }
     
        }
        return true;
    }

    bool colC(vector<vector<char>>& board, int col, char ch) {

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) {
                return false;
            }
        
        }
        return true;
    }

    bool box(vector<vector<char>>& board, int row, int col, char ch) {

        if (row >= 0 && row <= 2) row = 0;
        else if (row >= 3 && row <= 5) row = 3;
        else row = 6;

        if (col >= 0 && col <= 2) col = 0;
        else if (col >= 3 && col <= 5) col = 3;
        else col = 6;

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == ch) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {

        if (row > 8) {
            return true;
        }

        bool ans = false;

        if (board[row][col] == '.') {
            for (int no = 1; no <= 9; no++) {

                char ch = '0' + no;

                bool cond1 = rowC(board, row, ch);
                bool cond2 = colC(board, col, ch);
                bool cond3 = box(board, row, col, ch);

                if (cond1 && cond2 && cond3) {

                    board[row][col] = ch;

                    if (col < 8)
                        ans = solve(board, row, col + 1);
                    else
                        ans = solve(board, row + 1, 0);
                }

                if (ans == true)
                    break;
                else
                    board[row][col] = '.';
            }
        }
        else {
            if (col < 8)
                ans = solve(board, row, col + 1);
            else
                ans = solve(board, row + 1, 0);
        }

        return ans;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve(board, 0, 0);
    }
};
