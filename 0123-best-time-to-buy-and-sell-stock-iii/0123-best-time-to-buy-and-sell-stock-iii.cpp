#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int buy, int index, int k, vector<vector<vector<int>>> &dp) {
        if (index == prices.size() || k == 2)
            return 0;

        if (dp[index][buy][k] != INT_MIN)
            return dp[index][buy][k];

        int profit = 0;
        if (buy == 1) {
            int buykaro = -prices[index] + solve(prices, 0, index + 1, k, dp);
            int skipkaro = solve(prices, 1, index + 1, k, dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solve(prices, 1, index + 1, k + 1, dp);
            int skipkaro = solve(prices, 0, index + 1, k, dp);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, INT_MIN)));
        return solve(prices, 1, 0, 0, dp);
    }
};
