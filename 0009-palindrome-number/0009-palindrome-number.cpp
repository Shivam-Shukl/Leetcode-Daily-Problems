class Solution {
public:

    bool isPalindrome(int x) {
        if(x<0) return 0;
        string s = to_string(x);
        int n = s.size();
        int i =0,j= n-1;
        cout<<s;
        while(j>i){
            if(s[i] != s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
};