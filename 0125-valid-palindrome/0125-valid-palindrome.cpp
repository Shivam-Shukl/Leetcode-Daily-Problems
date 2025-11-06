class Solution {
public:
    bool palindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (j >= i) {
            if (s[i] != s[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }
    bool isalnum(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9')) {
            return true;
        } else {
            return false;
        }
    }

    bool isPalindrome(string s) {
        int n = s.size();
        string str = "";
        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                char ch = s[i];
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    ch = ch - 'A' + 'a';
                }
                str += ch;
            } else {
                continue;
            }
        }

        return palindrome(str);
    }
};