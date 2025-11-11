class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute force 
        // how will you approach to such problems.
        // create a map and store the 
        unordered_map<char,int> mp;
        int n = s.size();
        int maxi = 0;
        for(int i = 0;i<n;i++){
            int cnt =0;
            for(int j = i;j<n;j++){
                if(mp.find(s[j]) == mp.end()){
                    cnt++;
                    maxi = max(maxi,cnt);
                    mp[s[j]]++;
                }else{
                    break;
                }
            }
            mp.clear();
        }
        return maxi;
    }
};