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

   
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int val = 0; val <= 1; val++) {  // We can do at most 2 transactions (0 and 1 done)
                    int profit = 0;

                    if (buy == 1) {
                        int buykaro = -prices[index] + dp[index + 1][0][val];
                        int skipkaro = dp[index + 1][1][val];
                        profit = max(buykaro, skipkaro);
                    } else {
                        int sellkaro = 0;
                        if (val + 1 <= 2) {  // Only sell if we have transactions left
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

    int solveSpace(vector<int>& prices) {
        int n = prices.size();
      
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int val = 0; val <= 1; val++) {  
                    int profit = 0;

                    if (buy == 1) {
                        int buykaro = -prices[index] + next[0][val];
                        int skipkaro = next[1][val];
                        profit = max(buykaro, skipkaro);
                    } else {
                        int sellkaro = 0;
                        if (val + 1 <= 2) {  // Only sell if we have transactions left
                            sellkaro = prices[index] + next[1][val + 1];
                        }
                        int skipkaro = next[0][val];
                        profit = max(sellkaro, skipkaro);
                    }

                    curr[buy][val] = profit;
                }
                next = curr;
            }
        }

        return curr[1][0];
    }

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, INT_MIN)));
        // return solve(prices, 1, 0, 0, dp);

        // return solveTab(prices);

        return solveSpace(prices);
    }
};
