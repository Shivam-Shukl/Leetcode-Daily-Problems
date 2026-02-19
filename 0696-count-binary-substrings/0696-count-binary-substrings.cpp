class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int i = 0;
        int cnt1 = 0, cnt2 = 0;
        int ans = 0;

        while (i < n && s[i] == s[0]) {
            cnt1++;
            i++;
        }

        while (i < n) {
            cnt2 = 0;
            char val = s[i];   

            while (i < n && s[i] == val) {
                cnt2++;
                if (cnt2 <= cnt1) {
                    ans += 1;
                }
                i++;
            }

            cnt1 = cnt2;
        }

        return ans;
    }
};
