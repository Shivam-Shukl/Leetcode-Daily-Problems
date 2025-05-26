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
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Fill the table from bottom to top
        for (int index = n-1; index >= 0; index--) {
            for (int prevIndex = index-1; prevIndex >= -1; prevIndex--) {  // this part is where you lag.

                int notTake = dp[index+1][prevIndex+1];
                int take = 0;
                if (prevIndex == -1 || nums[prevIndex] < nums[index]) {
                    take = 1 + dp[index+1][index+1];
                }

                dp[index][prevIndex+1] = max(take, notTake);
            }
        }

        // The answer is for index = 0 and prevIndex = -1 → shifted by +1
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {

        // int n = nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MIN));
        // int prevIndex = -1;
        // return solve(nums,0,prevIndex,dp);

        return solveTab(nums);
    }
};