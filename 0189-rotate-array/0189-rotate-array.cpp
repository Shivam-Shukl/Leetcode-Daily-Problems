class Solution {
public:
    void rev(int i,int j,vector<int> &nums){
        while(j>i){
            swap(nums[i],nums[j]);
            j--,i++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <0) return;
        k = k%n;
        rev(0,n-k-1,nums);
        rev(n-k,n-1,nums);
        rev(0,n-1,nums);
    }
};