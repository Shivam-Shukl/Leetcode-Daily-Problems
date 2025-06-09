class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans) {
        if(index == nums.size()) {
            ans.push_back(v);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            v.push_back(nums[index]); 
            solve(index + 1, nums, v, ans);
            v.pop_back();            
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, nums, v, ans);
        return ans;
    }
};
