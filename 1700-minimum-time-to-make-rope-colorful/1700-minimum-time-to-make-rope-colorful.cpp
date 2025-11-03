class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int ans = 0;
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            vector<int> val;
            if (i + 1 < n && colors[i] == colors[i + 1]) {
                val.push_back(arr[i]);
            }
            while (i + 1 < n && colors[i] == colors[i + 1]) {
                val.push_back(arr[i + 1]);
                i = i + 1;
            }
            sort(val.begin(), val.end());
            for (int j = 0; j < (int)val.size() - 1; j++) {
                ans += val[j];
            }
        }
        return ans;
    }
};
