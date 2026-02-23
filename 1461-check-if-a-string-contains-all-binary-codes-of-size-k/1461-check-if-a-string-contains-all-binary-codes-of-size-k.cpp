class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int n = s.size();

        for (int i = 0; i <= n - k; i++) {
            string str = s.substr(i, k);
            st.insert(str);
        }

        if (st.size() >= (1 << k)) { // 2^k using bitwise
            return true;
        } else {
            return false;
        }
    }
};