class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        unordered_map<int,int>mp;  // assuming that no duplicate exits
        int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mp.find(target - arr[i]) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[target - arr[i]]);
            }
            mp[arr[i]] = i;
        }
        return ans;
        
    }
};