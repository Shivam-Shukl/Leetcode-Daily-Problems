class Solution {
public:
    int binaryGap(int no) {

        int ans = 0;
        int pre = -1;
        int cnt = 0;
        while (no) {
            int rem = no % 2;
            if (rem == 1) {
                if (pre != -1) {
                    ans = max(ans, cnt - pre);
                }
                pre = cnt;
            }
            no = no / 2;
            cnt++;
        }

        return ans;
    }
};