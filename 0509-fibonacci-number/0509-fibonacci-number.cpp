class Solution {
public:
    int solve(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i =2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    // int solve2(int n){
    //     int
    // }
    int fib(int n) {
        if(n==0) return 0;
        return solve(n);
    }
};