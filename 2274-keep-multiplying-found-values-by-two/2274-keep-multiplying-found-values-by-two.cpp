class Solution {
public:
    int findFinalValue(vector<int>& nums, int tar) {
        unordered_map<int,int>mp;
        int n= nums.size();
        for(int ele : nums){
            mp[ele]++;
        }
        while( mp.find(tar) != mp.end() ){
            tar = tar * 2;
        }
        return tar;
    }
};