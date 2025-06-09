class Solution {
public:
    int solve(int index , int operationNo, int k, vector<int>& prices)
    {
        if(index == prices.size())
            return 0;

        if(operationNo == 2*k)
            return 0;
        
        int profit = 0;
        if(operationNo %2 == 0)
        {
            int buykaro = -prices[index] + solve(index+1,operationNo+1,k,prices);
            int skipkaro = solve(index+1,operationNo , k ,prices);
            profit = max(buykaro, skipkaro);
        }
        else{
            int sellkaro = prices[index] + solve(index+1,operationNo+1,k,prices);
            int skipkaro = solve(index+1,operationNo,k,prices);
            profit = max(sellkaro, skipkaro);
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0,0,k,prices);
    }
};