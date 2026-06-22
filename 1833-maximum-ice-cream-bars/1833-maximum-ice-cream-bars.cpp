class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, costs[i]);
        }

        vector<int> temp(maxi + 1, 0);

        // Frequency count
        for (int i = 0; i < n; i++) {
            temp[costs[i]]++;
        }

        // Prefix sum
        for (int i = 1; i <= maxi; i++) {
            temp[i] = temp[i - 1] + temp[i];
        }
        vector<int> ans(n);

        // Counting sort
        for (int i = n - 1; i >= 0; i--) {
            ans[temp[costs[i]] - 1] = costs[i];
            temp[costs[i]]--;
        }

        int index = 0;
        long long  sum = 0;
        for (int x : ans) {
            sum += x;
            if(sum <= coins){
                index++;
            }
        }
        
        return index;
    }
};