class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = INT_MIN,mini = INT_MAX,n = nums.size();

        for(int i =0;i<n;i++){
            if(maxi < nums[i]){
                maxi = nums[i];
            }
            if(mini > nums[i]){
                mini = nums[i];
            }
        }
        return k*(maxi-mini);
    }
};