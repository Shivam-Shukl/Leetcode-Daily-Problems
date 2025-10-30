class Solution {
public:
    int solve(int idx,int val){
        int ans = 1;
        for(int i=0;i<idx;i++){
            ans  = ans * 26;
        }
        ans = ans * val;
        return ans;
    }
    int titleToNumber(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            char ch = s[i];
            int idx = n-1 - i;
            int val = ch - 'A'+1;
            ans = ans + solve(idx,val);
        }
        return ans;
    }
};