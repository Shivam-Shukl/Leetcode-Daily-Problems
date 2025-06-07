class Solution {
public:
    int solve(vector<int>& prices, int buy,int index,vector<vector<int>> &dp)
    {
        if(index == prices.size())
        {
            return 0;
        }
        
        if(dp[index][buy] !=INT_MIN )
        {
            return dp[index][buy];
        }

        int profit = 0;
        if(buy==1)
        {
            int buykaro =  -prices[index] + solve(prices,0,index+1,dp);
            int skipkaro = solve(prices ,1, index+1,dp);
            profit = max(buykaro,skipkaro);
        }
        else{
            int sellkaro = prices[index] + solve(prices,1,index+1,dp);
            int skipkaro = solve(prices,0,index+1,dp);
            profit = max(sellkaro,skipkaro);
        }
        return dp[index][buy] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,INT_MIN));
        return solve(prices,1,0,dp);
    }
};