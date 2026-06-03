class Solution {
public:
    int earliestFinishTime(vector<int>& LST, vector<int>& LD,
                           vector<int>& WST, vector<int>& WD) {
        int n = LST.size();
        int m = WST.size();

        int res1 = INT_MAX, res2 = INT_MAX;

        int val1 = INT_MAX;
        int val2 = INT_MAX;

        for (int i = 0; i < n; i++) {
            val1 = min(val1, LST[i] + LD[i]);
        }

        for (int i = 0; i < m; i++) {
            res1 = min(res1, max(WST[i], val1) + WD[i]);
        }

        for (int i = 0; i < m; i++) {
            val2 = min(val2, WST[i] + WD[i]);
        }

        for (int i = 0; i < n; i++) {
            res2 = min(res2, max(LST[i], val2) + LD[i]);
        }

        return min(res1, res2);
    }
};