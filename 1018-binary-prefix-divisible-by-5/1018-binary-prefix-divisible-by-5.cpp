class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int mod = 0;

        for(int bit : nums){
            mod = (mod * 2 + bit) % 5;
            ans.push_back(mod == 0);
        }

        return ans;
    }
};
