class Solution {
public:
    int getMax(vector<int>& arr,int i,int j)
    {
        int ans = 0;
        for(int k = i; k <= j; k++)
        {
            ans = max(ans, arr[k]);
        }
        return ans;
    }

    int solveRec(int i, int j, vector<int>& arr)
    {
        if(i == j)
        {
            return 0;  // only one leaf, no cost to combine
        }

        int ans = INT_MAX;
        for(int k = i; k < j; k++)
        {
            int val = getMax(arr, i, k) * getMax(arr, k + 1, j);
            long long total = 1LL * val + solveRec(i, k, arr) + solveRec(k + 1, j, arr);
            ans = min(ans, (int)total);
        }
        return ans;
    }

    int solveMemo(int i, int j, vector<int>& arr,vector<vector<int>> &dp)
    {
        if(i == j)
        {
            return 0;  // only one leaf, no cost to combine
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k = i; k < j; k++)
        {
            int val = getMax(arr, i, k) * getMax(arr, k + 1, j);
            long long total = 1LL * val + solveMemo(i, k, arr,dp) + solveMemo(k + 1, j, arr,dp);
            ans = min(ans, (int)total);
        }
        return dp[i][j] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n= arr.size();
        int i = 0;
        int j = n- 1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solveRec(i, j, arr);
        return solveMemo(i,j,arr,dp);
    }
};
