class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int val = min(m, n);
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + grid[i][0];
            grid[i][0] = sum;
        }
        sum = 0;
        for (int j = 0; j < m; j++) {
            sum = sum + grid[0][j];
            grid[0][j] = sum;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1] -
                             grid[i - 1][j - 1] + grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] <= k) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};