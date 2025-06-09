class Solution {
public:
    int solve(int index , int operationNo, int k, vector<int>& prices,vector<vector<int>> &dp)
    {
        if(index == prices.size())
            return 0;

        if(operationNo == 2*k)
            return 0;
        
        if(dp[index][operationNo] != -1)
            return dp[index][operationNo];

        int profit = 0;
        if(operationNo %2 == 0)
        {
            int buykaro = -prices[index] + solve(index+1,operationNo+1,k,prices,dp);
            int skipkaro = solve(index+1,operationNo , k ,prices,dp);
            profit = max(buykaro, skipkaro);
        }
        else{
            int sellkaro = prices[index] + solve(index+1,operationNo+1,k,prices,dp);
            int skipkaro = solve(index+1,operationNo,k,prices,dp);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][operationNo]=profit;
    }

    // int solveTab(int index , int operationNo, int k, vector<int>& prices)
    // {
    //     if(index == prices.size())
    //         return 0;

    //     if(operationNo == 2*k)
    //         return 0;
        
    //     int profit = 0;
    //     if(operationNo %2 == 0)
    //     {
    //         int buykaro = -prices[index] + solve(index+1,operationNo+1,k,prices);
    //         int skipkaro = solve(index+1,operationNo , k ,prices);
    //         profit = max(buykaro, skipkaro);
    //     }
    //     else{
    //         int sellkaro = prices[index] + solve(index+1,operationNo+1,k,prices);
    //         int skipkaro = solve(index+1,operationNo,k,prices);
    //         profit = max(sellkaro, skipkaro);
    //     }
    //     return profit;
    // }


    int maxProfit(int k, vector<int>& prices) {

        int n= prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1, -1));

        // return solve(0,0,k,prices,dp);

        return solve(0,0,k,prices,dp);
    }
};