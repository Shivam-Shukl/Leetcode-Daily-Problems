class Solution {
public:
    vector<string> solve(string text){
        vector<string> ans;
        string s= "";
        int i =0;
        while(i<text.size()){
            if(text[i] == ' '){
                i++;
                ans.push_back(s);
                s.erase();
            }else{
                s.push_back(text[i]);
                i++;
            }
        }
        if(!s.empty()){
            ans.push_back(s);
        }
        return ans;
    }
    int canBeTypedWords(string text, string pat) {
        vector<int> cnt(26,0);
        int n = pat.size();
        for(int i=0;i<n;i++){
            int idx = pat[i] - 'a';
            cnt[idx]++;
        }

        int ans = 0;
        vector<string> txt = solve(text);
        int m = txt.size();
        for(int i=0;i<m;i++){
            string s = txt[i];
            bool cond = true;
            for(int j= 0;j<s.size();j++){
                if(cnt[s[j] - 'a'] != 0){
                    cond =false;
                }
            }
            if(cond) ans++;
        }
       
        return ans;
    }
};