class Solution {
public:
    int solveRec(vector<int>& cost,int step){
    
        if(step <= -1) return 0;
        int first = cost[step] + solveRec(cost,step-1);
        int sec = cost[step] + solveRec(cost, step -2);

        return min(first, sec);
    }
    int solveTopDown(vector<int>& cost, int step,vector<int>& dp){
        if(step <= -1) return 0;
        if(dp[step] != -1) return dp[step];
        int first = cost[step] + solveTopDown(cost,step-1,dp);
        int sec = cost[step] + solveTopDown(cost, step -2,dp);

        return dp[step] = min(first, sec);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1,-1);
        return min(solveTopDown(cost,n-1,dp),solveTopDown(cost,n-2,dp));
    }
};