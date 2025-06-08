
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int buy, int index, int val,int k, vector<vector<vector<int>>> &dp) {
        
        if (index == prices.size() || val == k)
            return 0;

        if (dp[index][buy][val] != INT_MIN)
            return dp[index][buy][val];

        int profit = 0;
        if (buy == 1) {
            int buykaro = -prices[index] + solve(prices, 0, index + 1, val,k, dp);
            int skipkaro = solve(prices, 1, index + 1, val,k, dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[index] + solve(prices, 1, index + 1, val + 1,k, dp);
            int skipkaro = solve(prices, 0, index + 1, val, k,dp);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy][val] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, INT_MIN)));
        return solve(prices, 1, 0, 0,k, dp);
    }
};