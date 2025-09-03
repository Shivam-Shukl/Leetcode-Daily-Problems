class Solution {
public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        int ans =0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            if(mp[arr[i]] >= n/2){
                if( mp[arr[i]] > mp[ans]){
                    ans = arr[i];
                }else if(mp[arr[i]] == mp[ans]){
                    ans= max(ans,arr[i]);
                }
            }
        }
        return ans;
    }
};