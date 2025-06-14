class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped,
              vector<vector<int>>& dp) {
        if (index == nums1.size())
            return 0;

        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (dp[index][swapped] != -1) {
            return dp[index][swapped];
        }
        // catch
        if (swapped)
            swap(prev1, prev2);

        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, 0, dp);

        // swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1, dp));

        return dp[index][swapped] = ans;
    }
    int solveSpace(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
     
        vector<int> next(2, 0);
        vector<int> curr(2,0);

        for(int index = n-1;index>=1;index--)
        {
            for(int swapped = 0 ;swapped<=1 ;swapped++)
            {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // catch
                if (swapped)
                    swap(prev1, prev2);

                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = next[0];

                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + next[1]);

                curr[swapped] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int index = n-1;index>=1;index--)
        {
            for(int swapped = 0 ;swapped<=1 ;swapped++)
            {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // catch
                if (swapped)
                    swap(prev1, prev2);

                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0];

                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index+1][1]);

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // bool swapped = 0;
        // return solve(nums1, nums2, 1, swapped, dp);

        // return solveTab(nums1,nums2);

        return solveSpace(nums1,nums2);
    }
};