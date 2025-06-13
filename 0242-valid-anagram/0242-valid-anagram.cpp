class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> fir(26,0);
        vector<int> sec(26,0);
        for(int i=0;i<s.size();i++)
        {
            char ch1 = s[i],ch2 = t[i];
            fir[ch1 -'a']+= 1;
            sec[ch2 -'a'] += 1; 
        }
        for(int i=0;i<26;i++)
        {
            if(fir[i] != sec[i])
                return false;
        }
        return true;
    }
};