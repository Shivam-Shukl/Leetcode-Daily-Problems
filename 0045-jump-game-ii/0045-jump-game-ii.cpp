class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int> &dp) {
        int n = nums.size();

        if(ind == n-1) return 0;
        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MAX;
        for(int i = ind+1; i<n && i<= ind + nums[ind]; i++){
            int sub = solve(nums, i, dp);
            if(sub != INT_MAX){
                ans = min(ans, 1 + sub);
            }
        }
        return dp[ind] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int res = solve(nums,0,dp);
        return (res == INT_MAX) ? -1 : res;
    }
};
