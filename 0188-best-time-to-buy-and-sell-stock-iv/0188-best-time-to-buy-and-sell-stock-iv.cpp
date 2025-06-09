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

    int solveTab(vector<int>& prices,int k)
    {

        int n= prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1, 0));

        for(int index = n-1;index >= 0;index--)
        {
            for(int operationNo = 2*k-1;operationNo >=0;operationNo--)
            {
                int profit = 0;
                if(operationNo %2 == 0)
                {
                    int buykaro = -prices[index] + dp[index+1][operationNo+1];
                    int skipkaro =  dp[index+1][operationNo];
                    profit = max(buykaro, skipkaro);
                }
                else{
                    int sellkaro = prices[index] +  dp[index+1][operationNo+1];;
                    int skipkaro =  dp[index+1][operationNo];
                    profit = max(sellkaro, skipkaro);
                }
                dp[index][operationNo]=profit;
            }
        }
        return dp[0][0];
        
    }

    int maxProfit(int k, vector<int>& prices) {

        // int n= prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2*k+1, -1));

        // return solve(0,0,k,prices,dp);

        // return solve(0,0,k,prices,dp);

        return solveTab(prices,k);
    }
};