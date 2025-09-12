class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ans1(26,0);
        vector<int> ans2(26,0);
        for(char ch : s){
            ans1[ch-'a']++;
        }
        for(char ch : t){
            ans2[ch - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(ans1[i] != ans2[i]){
                return false;
            }
        }
        return true;
    }
};