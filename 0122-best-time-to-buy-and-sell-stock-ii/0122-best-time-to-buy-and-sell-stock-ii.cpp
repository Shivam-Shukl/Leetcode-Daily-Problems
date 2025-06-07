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

    int solveTab(vector<int>& prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index = n-1;index>=0;index--)
        {
            for(int buy = 0 ;buy<2;buy++)
            {
                int profit = 0;
                if(buy==1)
                {
                    int buykaro =  -prices[index] + dp[index+1][0];
                    int skipkaro = dp[index+1][1];
                    profit = max(buykaro,skipkaro);
                    
                }
                else{

                    int sellkaro = prices[index] +dp[index+1][1]; 
                    int skipkaro = dp[index+1][0];
                    profit = max(sellkaro,skipkaro);

                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSpace(vector<int>& prices)
    {

        int n = prices.size();
    

        vector<int> next(2,0);
        vector<int> curr(2,0);

        for(int index = n-1;index>=0;index--)
        {
            for(int buy = 0 ;buy<2;buy++)
            {
                int profit = 0;
                if(buy==1)
                {
                    int buykaro =  -prices[index] + next[0];
                    int skipkaro = next[1];
                    profit = max(buykaro,skipkaro);
                    
                }
                else{

                    int sellkaro = prices[index] + next[1];
                    int skipkaro = next[0];
                    profit = max(sellkaro,skipkaro);

                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,INT_MIN));
        // return solve(prices,1,0,dp);
        // return solveTab(prices);
        return solveSpace(prices);
    }
};