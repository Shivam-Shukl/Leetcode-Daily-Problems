
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

    int solveTab(vector<int>& prices,int k) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int val = 0; val <= k; val++) {  // We can do at most 2 transactions (0 and 1 done)
                    int profit = 0;

                    if (buy == 1) {
                        int buykaro = -prices[index] + dp[index + 1][0][val];
                        int skipkaro = dp[index + 1][1][val];
                        profit = max(buykaro, skipkaro);
                    } else {
                        int sellkaro = 0;
                        if (val + 1 <= k) {  // Only sell if we have transactions left
                            sellkaro = prices[index] + dp[index + 1][1][val + 1];
                        }
                        int skipkaro = dp[index + 1][0][val];
                        profit = max(sellkaro, skipkaro);
                    }

                    dp[index][buy][val] = profit;
                }
            }
        }

        return dp[0][1][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, INT_MIN)));
        // return solve(prices, 1, 0, 0,k, dp);
        return solveTab(prices,k);
    }
};