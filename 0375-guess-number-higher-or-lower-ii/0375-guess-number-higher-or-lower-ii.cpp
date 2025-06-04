class Solution {
public:
    int solve(int start ,int end)
    {
        // base case
        if(start >= end)
        {
            return 0;
        }

        int ans = INT_MAX;
        for(int i=start ;i<= end;i++)
        {
            int left = solve(start,i-1);
            int right = solve(i+1,end);
            int val = i + max(left,right);
            ans = min(ans,val);
        }
        return ans;
    }
    int getMoneyAmount(int n) {
        return solve(1,n);   
    }
};