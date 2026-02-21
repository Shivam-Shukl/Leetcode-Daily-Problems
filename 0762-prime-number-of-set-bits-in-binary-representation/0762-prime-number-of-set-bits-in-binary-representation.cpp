class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i); // C++ built-in to count set bits
            if (st.contains(setBits)) {
                ans++;
            }
        }
        return ans;
    }
};