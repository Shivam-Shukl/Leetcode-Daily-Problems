class Solution {
public:
    int solve(string temp, int bit) {
        int cnt = 0;
        int n = temp.size();
        for (int i = 1; i < n; i++) {
            if ((temp[i] == '0' && bit == 1) || (temp[i] == '1' && bit == 0)) {
                cnt++;
            }
            if (bit == 0)
                bit = 1;
            else
                bit = 0;
        }
        return cnt;
    }
    int minOperations(string s) {
        int n = s.size();

        // first method s[i] = '1'
        int cnt = 0;
        if (s[0] == '0') {
            cnt++;
        }
        cnt = cnt + solve(s, 0);

        int val = 0;
        if (s[0] == '1') {
            val++;
        }
        val = val + solve(s, 1);

        return min(val, cnt);
    }
};