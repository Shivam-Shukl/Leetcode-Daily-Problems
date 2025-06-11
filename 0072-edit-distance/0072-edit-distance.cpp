class Solution {
public:
    long long solve(string& word1, string& word2, int ind1, int ind2, vector<vector<long long>> &dp) 
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
            long long insertOp = 1 + solve(word1, word2, ind1, ind2 + 1, dp);     // simulate insert
            long long deleteOp = 1 + solve(word1, word2, ind1 + 1, ind2, dp);     // simulate delete
            long long replaceOp = 1 + solve(word1, word2, ind1 + 1, ind2 + 1, dp);// simulate replace

            return dp[ind1][ind2] = min({insertOp, deleteOp, replaceOp});
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
        return (int)solve(word1, word2, 0, 0, dp);
    }
};
