class Solution {
public:
    int binaryGap(int no) {

        string s = "";
        while (no) {
            int rem = no % 2;
            no = no / 2;
            s += (rem + '0');
        }

        int i = 0, n = s.size();
        int ans = 0;

        while (i < n) {
            if (s[i] == '1') {
                int j = i + 1;
                // find the next 1 index;
                while (j < n && s[j] == '0') {
                    j++;
                }

                if (j < n && s[j] == '1') {
                    ans = max(ans, j - i);
                }
                i = j;

            } else {
                i++;
            }
        }
        return ans;
    }
};