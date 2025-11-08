class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& val,int ind){
        if(ind == nums.size()){
            ans.push_back(val);
            return;
        }
        solve(nums,ans,val,ind+1);
        val.push_back(nums[ind]);
        solve(nums, ans, val, ind+1);
        val.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> val;
        vector<vector<int>> ans;
        solve(nums,ans,val,0);
        return ans;
    }
};