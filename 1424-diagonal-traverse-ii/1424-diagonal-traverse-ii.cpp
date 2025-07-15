class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        int n = nums.size();
      
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size() ;j++)
            {
                int ind = i+j;
                mp[ind].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        vector<int> temp;
        for(auto it = mp.begin();it!=mp.end() ;++it)
        {
            temp = it->second;
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++)
            {
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};