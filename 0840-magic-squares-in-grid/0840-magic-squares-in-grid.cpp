class Solution {
public:
    bool help(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        bool unique = false;
        bool one = false, two = false, three = false, four = false,
             five = false, six = false, seven = false, eight = false,
             nine = false;

        for (int row = i; row < i + 3; row++) {
            for (int col = j; col < j + 3; col++) {
                int val = grid[row][col];

                if (val == 1) one = true;
                else if (val == 2) two = true;
                else if (val == 3) three = true;
                else if (val == 4) four = true;
                else if (val == 5) five = true;
                else if (val == 6) six = true;
                else if (val == 7) seven = true;
                else if (val == 8) eight = true;
                else if (val == 9) nine = true;
            }
        }

        if (one && two && three && four && five && six && seven && eight && nine) {
            unique = true;
        }

        bool rowSum = true;
        int sum = 0;
        int cnt = 0;
        int r = 0;

        for (int row = i; row < i + 3; row++) {
            cnt = 0;
            for (int col = j; col < j + 3; col++) {
                cnt += grid[row][col];
            }

            if (row == i) {
                sum = cnt;
                r = sum;
            } else if (sum != cnt) {
                rowSum = false;
                break;
            }
        }

        bool colSum = true;
        sum = 0;
        cnt = 0;
        int c = 0;

        for (int col = j; col < j + 3; col++) {
            cnt = 0;
            for (int row = i; row < i + 3; row++) {
                cnt += grid[row][col];
            }

            if (col == j) {
                sum = cnt;
                c = sum;
            } else if (sum != cnt) {
                colSum = false;
                break;
            }
        }

        bool cond = false;
        int d1 = 0;

        int row = i, col = j;
        while (row < i + 3 && col < j + 3) {
            d1 += grid[row][col];
            row++;
            col++;
        }

        int d2 = 0;
        row = i + 2;
        col = j;
        while (row >= i && col < j + 3) {
            d2 += grid[row][col];
            row--;
            col++;
        }

        if (r == c && c == d1 && d1 == d2) {
            cond = true;
        }

        return (colSum && rowSum && unique && cond);
    }

    int solve(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n < 3 || m < 3)
            return 0;

        int cnt = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (i + 2 < n && j + 2 < m) {
                    if (help(i, j, grid)) {
                        cnt += 1;
                    }
                }
            }
        }
        return cnt;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        return solve(grid);
    }
};
