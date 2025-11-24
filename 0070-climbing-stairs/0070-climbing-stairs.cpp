class Solution {
public:
    int solveRec(int n){
        if(n==0){
            return 1;
        }
        if(n<0) return 0;

        int one = solveRec(n-1);
        int two = solveRec(n-2);
        return one+two;
    }
    int solveTopDown(int n,vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];

        int one = solveTopDown(n-1,dp);
        int two = solveTopDown(n-2,dp);
        return dp[n] = one+two;
    }
    int solveBottomUp(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
      
        for(int i =2;i<=n;i++){
            dp[i]  = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        
        return solveBottomUp(n);
    }
};