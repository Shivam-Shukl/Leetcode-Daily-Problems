class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        int i =0;
        while(i<n && nums[i]!= 1){
            i++;
        }
        int first = i;
        i= i+1;
        for(;i<n;i++){
            if(nums[i] == 1){
                mini = min(mini,i - first-1);
                first = i;
            }
        }
        return mini >= k;
    }
};