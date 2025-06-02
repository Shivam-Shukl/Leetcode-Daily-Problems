class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        int n = nums.size();

        if (n <= 2)
            return n;

        vector<unordered_map<int, int>> dp(n);  
        int ans = 1; 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) { 
                int diff = nums[i] - nums[j];
                if(diff != difference)
                {
                    continue;
                }else{
                    int cnt = 1;

                    if (dp[j].count(diff))
                        cnt = dp[j][diff];

                    dp[i][diff] = 1 + cnt;
                    ans = max(ans, dp[i][diff]);
                }
                
            }
        }
        return ans;
    }
};

