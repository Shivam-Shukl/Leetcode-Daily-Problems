class Solution {
public:
    int solve(int n) {
     
        string s = "";
        while (n) {
            int rem = n % 2;
            n = n / 2;
            s.push_back(rem + '0');
        }
        n = s.size();
        while (n < 32) {
            s.push_back('0');
            n++;
        }
      
        uint32_t val = 0;
        uint32_t pow = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];
            if (ch == '1') {
                val += pow;
            }
            pow = pow * 2;
        }
        return val;
    }

    int reverseBits(int n) { 
        return solve(n); 
    }
};