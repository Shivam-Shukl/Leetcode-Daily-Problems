class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int zero_at_even = 0;
        int zero_at_odd = 0;
        int one_at_even = 0;
        int one_at_odd = 0;

        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {
                if (s[i] == '0')
                    zero_at_even++;
                else
                    one_at_even++;
            } else {
                if (s[i] == '1')
                    one_at_odd++;
                else
                    zero_at_odd++;
            }
        }

        // configuration 1: 1 at even, 0 at odd
        // configuration 2: 0 at even, 1 at odd
        return min(zero_at_even + one_at_odd, zero_at_odd + one_at_even);
    }
};