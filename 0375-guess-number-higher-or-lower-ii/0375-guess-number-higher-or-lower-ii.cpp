class Solution {
public:
    int solve(int start ,int end,vector<vector<int>> &dp)
    {
        // base case
        if(start >= end)
        {
            return 0;
        }

        if(dp[start][end]!= -1)
        {
            return dp[start][end];
        }

        int ans = INT_MAX;
        for(int i=start ;i<= end;i++)
        {
            int left = solve(start,i-1,dp);
            int right = solve(i+1,end,dp);
            int val = i + max(left,right);
            ans = min(ans,val);
        }
        return dp[start][end] = ans;
    }

    int solveTab(int n)
    {

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        // base case

        for(int start = n ;start>=1;start--)
        {
            for(int end=0 ;end <=n;end++)
            {
                if(start == end)
                {
                    continue;
                }else{
                    int ans = INT_MAX;
                    for(int i=start ;i<= end;i++)
                    {
                        int left = solve(start,i-1,dp);
                        int right = solve(i+1,end,dp);
                        int val = i + max(left,right);
                        ans = min(ans,val);
                    }
                    dp[start][end] = ans;
                }
            }
        }
        
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // return solve(1,n,dp);   
        return solveTab(n);
    }
};