class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n-1;
        while(s[i] == ' '){
            i--;
        }
        int ind = 0;
        while(i>=0 && s[i] != ' '){
            ind++;
            i--;
        }
        return ind;
    }
};