class Solution {
public:
    int solve(string& word1, string& word2, int ind1, int ind2, vector<vector<int>> &dp) 
    {
        if (ind1 == word1.size())
             return word2.size() - ind2;
        if (ind2 == word2.size()) 
            return word1.size() - ind1;

        if (dp[ind1][ind2] != -1) 
            return dp[ind1][ind2];

        if (word1[ind1] == word2[ind2]) {
            return dp[ind1][ind2] = solve(word1, word2, ind1 + 1, ind2 + 1, dp);
        } else {
            int insertOp = 1 + solve(word1, word2, ind1, ind2 + 1, dp);     // simulate insert
            int deleteOp = 1 + solve(word1, word2, ind1 + 1, ind2, dp);     // simulate delete
            int replaceOp = 1 + solve(word1, word2, ind1 + 1, ind2 + 1, dp);// simulate replace

            return dp[ind1][ind2] = min({insertOp, deleteOp, replaceOp});
        }
    }

    int solveTab(string& word1, string& word2) 
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for(int ind2 = 0;ind2 <= m;ind2++)
        {
            dp[n][ind2] = word2.size() - ind2;
        }
        for(int ind1 = 0;ind1 <= n;ind1++ )
        {
            dp[ind1][m] = word1.size() - ind1;
        }
        

        for(int ind1 = n-1;ind1>=0;ind1--)
        {
            for(int ind2 = m-1;ind2>=0 ;ind2--)
            {
                if (word1[ind1] == word2[ind2]) {
                    dp[ind1][ind2] = dp[ind1+1][ind2+1];
                } else {
                    int insertOp = 1 + dp[ind1][ind2+1]; 
                    int deleteOp = 1 + dp[ind1+1][ind2];     
                    int replaceOp = 1 + dp[ind1+1][ind2+1];

                    dp[ind1][ind2] = min({insertOp, deleteOp, replaceOp});
                }
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        // int n = word1.size(), m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solve(word1, word2, 0, 0, dp);

        return solveTab(word1,word2);
    }
};
