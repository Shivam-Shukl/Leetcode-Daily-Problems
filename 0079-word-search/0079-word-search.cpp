class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,
               vector<vector<bool>> &vis, int ind, int i, int j) {

        if (ind == word.size()) {
            return true;
        }
        
        int n = board.size();
        int m = board[0].size();
        // four directio
        bool left = false; // (i,j-1)

        if (j - 1 >= 0 && board[i][j - 1] == word[ind] && 
            vis[i][j - 1] == false) {
   
            vis[i][j - 1] = true;
            left = solve(board, word, vis, ind + 1, i, j - 1);
            vis[i][j-1] = false;
        }

        bool right = false; //(i,j+1)
        if (j + 1 < m && board[i][j + 1] == word[ind] && 
            vis[i][j + 1] == false) {
       
            vis[i][j + 1] = true;
            right = solve(board, word, vis, ind + 1, i, j + 1);
            vis[i][j+1] = false;
        }

        bool upper = false; // i-1 ,j
        if (i - 1 >= 0 && board[i - 1][j] == word[ind] &&
            vis[i - 1][j] == false) {
  
            vis[i - 1][j] = true;
            upper = solve(board, word, vis, ind + 1, i - 1, j);
            vis[i-1][j] = false;
        }

        bool down = false; // i+1,j
        if (i + 1 < n && board[i + 1][j] == word[ind] &&
            vis[i + 1][j] == false) {
    
            vis[i + 1][j] = true;
            down = solve(board, word, vis, ind + 1, i+1,j);
            vis[i+1][j] = false;
        }

        return (left || right || upper || down);
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {

                    vis[i][j] = true;
                    if (solve(board, word, vis, 1, i, j)) {
                        return true;
                    }
                    vis[i][j] = false;
                 
                }
            }
        }
        return false;
    }
};