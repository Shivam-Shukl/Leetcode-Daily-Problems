#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int zero_at_even = 0;
        int zero_at_odd = 0;
        int one_at_even = 0;
        int one_at_odd = 0;
        int cnt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] == '0')
                    zero_at_even++;
                else
                    one_at_even++;
            } 
            else {
                if (s[i] == '1')
                    one_at_odd++;
                else
                    zero_at_odd++;
            }
        }

        cnt = min(one_at_even + zero_at_odd, one_at_odd + zero_at_even);

        for (int i = 1; i < n; i++) {

            swap(zero_at_even, zero_at_odd);
            swap(one_at_even, one_at_odd);

            if (s[i - 1] == '0') {
                zero_at_odd -= 1;

                if (n % 2 == 1)
                    zero_at_even += 1;
                else
                    zero_at_odd += 1;
            } 
            else {
                one_at_odd -= 1;

                if (n % 2 == 1)
                    one_at_even += 1;
                else
                    one_at_odd += 1;
            }

            cnt = min({one_at_even + zero_at_odd, one_at_odd + zero_at_even, cnt});
        }

        return cnt;
    }
};