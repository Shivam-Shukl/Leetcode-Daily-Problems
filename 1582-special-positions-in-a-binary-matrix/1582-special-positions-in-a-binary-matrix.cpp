class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    //
                    bool cond1 = true;
                    for (int k = 0; k < m; k++) {
                        if (k != i && mat[k][j] == 1) {
                            cond1 = false;
                            break;
                        }
                    }
                    bool cond2 = true;
                    if (cond1) {
                        for (int k = 0; k < n; k++) {
                            if (k != j && mat[i][k] == 1) {
                                cond2 = false;
                                break;
                            }
                        }
                    }
                    if (cond1 && cond2)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};