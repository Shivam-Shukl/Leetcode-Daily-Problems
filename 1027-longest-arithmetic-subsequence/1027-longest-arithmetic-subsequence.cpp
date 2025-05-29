class Solution {
public:
    int bruteForce(vector<int>&nums)
    {
        int n = nums.size();
        if(n<=2)
            return n;
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int fir = nums[i];
                int sec = nums[j];
                int dif = nums[j]-nums[i];
                int k = i-1;
                int val =2;
                while(k>=0)
                {
                    if(fir - nums[k] == dif)
                    {
                        val +=1;
                        fir = nums[k];
                    }
                    k--;
                }
                ans = max(ans,val);
            }
        }
        return ans;
    }
    int solve(int index, int diff, vector<int>& nums, vector<unordered_map<int, int>>& dp)
    {
        if (index < 0)
            return 0;

        if (dp[index].count(diff))
        {
            return dp[index][diff];
        }

        int ans = 0;
        for (int j = index - 1; j >= 0; j--)
        {
            if (nums[index] - nums[j] == diff)
            {
                ans = max(ans, 1 + solve(j, diff, nums, dp));
            }
        }
        return dp[index][diff] = ans;
    }

    int longestArithSeqLength(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;

        int ans = 0;

        vector<unordered_map<int, int>> dp(n);  // FIXED: vector of maps

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums, dp));
            }
        }
        return ans;
    }
};