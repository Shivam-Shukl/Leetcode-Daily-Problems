class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int n,int k ,int target,vector<vector<int>> &dp)
    {
        // base case
        if(target <= 0)
        {
            return 0;
        }
        if(n == 1)
        {
            if(target <= k)
            {
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[n][target] != -1)
        {
            return dp[n][target];
        }
        
        int ans = 0;
        for(int i=1;i<=k ;i++)
        {
            ans =(ans%mod +  solve(n-1,k,target - i,dp)%mod)%mod;
        }

        return dp[n][target] = ans;

    }
    int solveTab(int n, int k, int target) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // base case: with 1 dice, you can only form sums from 1 to k
        for (int sum = 1; sum <= k && sum <= target; sum++) {
            dp[1][sum] = 1;
        }

        for (int dice = 2; dice <= n; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                int ways = 0;
                for (int face = 1; face <= k; face++) {
                    if (sum - face >= 0) {
                        ways = (ways + dp[dice - 1][sum - face]) % mod;
                    }
                }
                dp[dice][sum] = ways;
            }
        }
        
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {

        // vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        // return solve(n,k,target,dp);
        return solveTab(n,k,target);
    }
};