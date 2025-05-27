class Solution {
public:
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
            vector<vector<int>> dp(n,vector<int>(target+1,-1));
            return solve(nums,target,n-1,dp);
        }
    }
};