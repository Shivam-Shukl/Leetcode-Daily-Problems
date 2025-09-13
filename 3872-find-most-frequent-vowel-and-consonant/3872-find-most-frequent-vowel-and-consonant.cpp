class Solution {
public:
    
    int maxFreqSum(string s) {
        vector<int> cnt(26,0);
        for(char ch : s){
            cnt[ch-'a']++;
        }
        int vowel = 0,cst = 0;
        for(int i=0;i<26;i++){
            char ch = 'a' + i;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowel = max(vowel , cnt[i]);
            }else{
                cst = max(cst,cnt[i]);
            }
        }
        return vowel+ cst;

    }
};