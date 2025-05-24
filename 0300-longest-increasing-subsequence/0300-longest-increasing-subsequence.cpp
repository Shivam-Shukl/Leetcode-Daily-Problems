class Solution {
public:

    int solve(vector<int>& nums,int index,int prevIndex,vector<vector<int>>&dp)
    {
        if(index == nums.size())
        {
            return 0;
        }
        if(dp[index][prevIndex+1] != INT_MIN )
        {
            return dp[index][prevIndex+1];
        }
        int exc = solve(nums,index+1,prevIndex,dp);
        
        int inc = 0;
        if(prevIndex==-1 || nums[prevIndex]< nums[index])
        {
         
            inc = 1+ solve(nums,index+1,index,dp);
        }

        return dp[index][prevIndex+1]= max(inc,exc);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,INT_MIN));
        int prevIndex = -1;
        return solve(nums,0,prevIndex,dp);
    }
};