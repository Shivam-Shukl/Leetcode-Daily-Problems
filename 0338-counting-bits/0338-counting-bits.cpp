class Solution {
public:
    int solve(int n)
    {
        int cntOne =0;
        while(n != 0)
        {
            int digit = n %2;
            n = n/2;
            if(digit == 1)
            {
                cntOne++;
            }
        }
        return cntOne;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            ans[i] = solve(i);
        }
        return ans;
    }
};