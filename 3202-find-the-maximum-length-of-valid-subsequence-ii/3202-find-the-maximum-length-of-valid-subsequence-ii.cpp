class Solution {
public:
    int solve(vector<int>& nums, int k, int ind,int prev,int val, vector<vector<int>> &dp){

        if(ind == nums.size())
        {
            return 0;
        }

        if(dp[ind][prev+1] != -1)
        {
            return dp[ind][prev+1];
        }

        int exc = solve(nums,k,ind+1,prev,val,dp);

        int inc = 0;
        if((prev == -1) || ((nums[prev] + nums[ind]) %k == val ))
        {
            prev = ind;
            inc = 1 + solve(nums,k,ind+1,prev,val,dp);
        }
        return dp[ind][prev+1] = max(inc,exc);
    }
    int maximumLength(vector<int>& nums, int k) {
        
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        for(int val = 0;val <= k-1;val++)
        {
            ans = max(ans,solve(nums,k,0,-1,val,dp));
            dp.assign(n+1, vector<int>(n+1, -1));
        }
        return ans;
    }
};