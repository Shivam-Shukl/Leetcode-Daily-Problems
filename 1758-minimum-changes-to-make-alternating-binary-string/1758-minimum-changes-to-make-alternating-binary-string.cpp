class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string temp = s;
        // first method s[i] = '1'
        int cnt = 0;
        if (temp[0] == '0') {
            cnt++;
        }
        int bit = 0;
        for (int i = 1; i < n; i++) {
            if ((temp[i] == '0' && bit == 1) || (temp[i] == '1' && bit == 0)) {
                cnt++;
            }
            if (bit == 0)
                bit = 1;
            else
                bit = 0;
        }

        int val = 0;
        if (temp[0] == '1') {
            val++;
        }
        bit = 1;
        for (int i = 1; i < n; i++) {
            if ((temp[i] == '0' && bit == 1) || (temp[i] == '1' && bit == 0)) {
                val++;
            }
            if (bit == 0)
                bit = 1;
            else
                bit = 0;
        }
        return min(val, cnt);
    }
};