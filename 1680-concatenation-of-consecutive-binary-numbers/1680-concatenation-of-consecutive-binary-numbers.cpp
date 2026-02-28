class Solution {
public:
    string help(int n) {
        string val = "";
        while (n) {
            int rem = n % 2;
            val.push_back(rem + '0');
            n = n / 2;
        }
        reverse(val.begin(), val.end());
        return val;
    }
    int concatenatedBinary(int n) {
        const long long M = 1e9 + 7;
        string ans = "";
        for (int i = 1; i <= n; i++) {
            string str = help(i);
            ans += str;
        }
        int val = 0;
        unsigned long long mul = 1;

        for (int i = ans.size() - 1; i >= 0; i--) {
            val = (val + mul * (ans[i] - '0')) % M;
            mul = (mul * 2) % M;
        }
        return val;
    }
};