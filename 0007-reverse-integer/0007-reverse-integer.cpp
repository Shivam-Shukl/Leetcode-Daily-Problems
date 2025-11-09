class Solution {
public:
    int reverse(int x) {
        long long num = 0; // <-- 64-bit to prevent overflow during calc
        while (x) {
            int digit = x % 10;
            x /= 10;
            num = num * 10 + digit;
            if (num > INT_MAX || num < INT_MIN) // check overflow
                return 0;
        }
        return (int)num;
    }
};
