class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j<n&& i<n){
            int ele = nums[j];
            while(j+1 < n && nums[j+1] == nums[j]){
                j++;
            }
            j++;
           
            nums[i] = ele;
            i++;
        }
        return i;
    }
};