class Solution {
public:
    bool isAnagram(string a,string b){
        int n = a.size();
        int m = b.size();
        vector<int> cnt1(26,0);
        vector<int> cnt2(26,0);
        for(int i=0;i<n;i++){
            cnt1[a[i] - 'a']++;
        }
        for(int i = 0;i<m;i++){
            cnt2[b[i] - 'a']++;
        }
        for(int i =0;i<26;i++){
            if(cnt1[i] != cnt2[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        int n = words.size();
        for(int i=1;i<n;i++){
            string val = ans.back();
            if(!isAnagram(val,words[i])){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};