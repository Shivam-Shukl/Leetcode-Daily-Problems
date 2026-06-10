class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int val = nums[0];
        for(int i =1;i<n;i++){
            ans[i] = val;
            val = val + nums[i];
        }
        val = 0;
        for(int i =n-1;i>= 0 ;i--){
            ans[i] = abs(ans[i] - val);
            val = val + nums[i];
        }
        return ans;
    }
};