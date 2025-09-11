class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // kya kya aa raha hi 
        int n = nums.size();
        vector<int> ans(n,0);
        int cnt = 0;
        int mul = 1;
        for(int i =0;i<n;i++){
            if(nums[i] == 0){
                cnt++;
            }else{
                mul = mul * nums[i];
            }
        }
        if(cnt >= 2){
            return ans;
        }
        for(int i= 0;i<n;i++){
            if(cnt == 1 && nums[i] != 0){
                continue;
            }else if(cnt == 1 && nums[i] == 0){
                ans[i] = mul;
            }else if(nums[i] != 0){
                ans[i] = mul / nums[i];
            }
        }
        return ans;
    }
};