class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = "";
        int n = words.size();
        unordered_map<int,char> mp;
        char ch = 'a';
        for(int i = 25;i>= 0;i--){
            mp[i] = ch;
            ch = ch + 1;
        }

        for(int i =0;i<n;i++){
            string temp = words[i];
            int ans = 0;
            for(char ch : temp){
                int j = ch - 'a';
                ans += weights[j];
            }     
            ans = ans % 26;
            s.push_back(mp[ans]);
        }
        return s;
    }
};