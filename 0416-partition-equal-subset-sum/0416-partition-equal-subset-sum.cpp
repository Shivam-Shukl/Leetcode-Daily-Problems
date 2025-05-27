class Solution {
public:
    // top down dp 
    bool solve(vector<int>& arr, int target, int index,
               vector<vector<int>>& dp) {

        if (target == 0) {
            return true;
        }
        if (target < 0)
            return false;
        if (index < 0) {
            return false;
        }

        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        bool exclude = solve(arr, target, index - 1, dp);
        bool include = solve(arr, target - arr[index], index - 1, dp);

        if (exclude || include) {
            dp[index][target] = 1;
        } else {
            dp[index][target] = 0;
        }

        return dp[index][target];
    }
    // bottom up approach
    bool solveTab(vector<int>& arr, int target) {

        int n =arr.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));

        for(int i=0;i<n;i++)
        {
            dp[i][0] = 1;
        }
        

        for(int index = 0;index <n;index++)
        {
            for(int currSum = 1;currSum<= target;currSum++)
            {
                bool exclude =false;
                if(index-1 >=0)
                    exclude = dp[index-1][currSum];
                bool include = false;
                if(index -1 >= 0 && currSum -arr[index] >=0)
                    include = dp[index-1][currSum-arr[index]];

                if (exclude || include) {
                    dp[index][currSum] = 1;
                } else {
                    dp[index][currSum] = 0;
                }
            }
        }
        return dp[n-1][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        } else {
            int n =nums.size();
            int target = sum /2;
            // vector<vector<int>> dp(n,vector<int>(target+1,-1));
            // return solve(nums,target,n-1,dp);

            return solveTab(nums,target);
        }
    }
};