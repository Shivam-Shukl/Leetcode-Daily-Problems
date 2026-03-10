class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j][0] = Valid combinations with i zeros, j ones, ending in 0
        // dp[i][j][1] = Valid combinations with i zeros, j ones, ending in 1
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));

        // Base cases: purely 0s
        for (int i = 1; i <= min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        
        // Base cases: purely 1s
        for (int j = 1; j <= min(one, limit); j++) {
            dp[0][j][1] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                
                // 1. Calculate combinations ending in 0
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                
                // If we have enough zeros to exceed the limit, subtract the invalid cases
                if (i > limit) {
                    dp[i][j][0] = (dp[i][j][0] - dp[i - 1 - limit][j][1] + MOD) % MOD;
                }
                
                // 2. Calculate combinations ending in 1
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                
                // If we have enough ones to exceed the limit, subtract the invalid cases
                if (j > limit) {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - 1 - limit][0] + MOD) % MOD;
                }
            }
        }

        // The answer is the sum of valid strings ending in 0 and ending in 1
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};