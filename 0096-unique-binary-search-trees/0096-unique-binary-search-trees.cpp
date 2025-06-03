class Solution {
public:
    int solve(int n)
    {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        
        for(int i = 2 ;i<=n;i++)
        {
            int left = 0;
            int right = i-1;
            int index =0;
            int ans =0;
            if(i%2 ==0)
            {
                index = i/2;
            }else{
                index = i/2 +1;
            }
            for(int j= 1 ;j<=index ;j++){
                if(left == right)
                {
                    ans += dp[left]*dp[right];
                }else{
                    ans += 2*(dp[left]*dp[right]);
                    left++, right--;
                }
            }
            dp[i] = ans;
        }

        return dp[n];
    }
    int numTrees(int n) {
        return solve(n);
    }
};