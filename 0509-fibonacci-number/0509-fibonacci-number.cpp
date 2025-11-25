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
    int solve2(int n){
        int prev = 0;
        int curr = 1;
        for(int i = 2;i<=n;i++){
            int ele = curr + prev;
            prev = curr;
            curr = ele;
        }
        return curr;
    }
    int fib(int n) {
        if(n==0) return 0;
        return solve2(n);
    }
};