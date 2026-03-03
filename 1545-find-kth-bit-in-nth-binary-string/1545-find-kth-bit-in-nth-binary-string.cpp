class Solution {
public:
    string invert(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        return s;
    }
    char findKthBit(int n, int k) {

        string val = "0";
        for (int i = 2; i <= n; i++) {
            string temp = val;
            val.push_back('1');

            temp = invert(temp);

            reverse(temp.begin(), temp.end());

            val = val + temp;
        }

        return val[k - 1];
    }
};