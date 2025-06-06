class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans = 0;
        int n= arr.size();
        int mini = arr[0];
        int profit =0;
        for(int i =1;i<n;i++)
        {
            int newProfit = arr[i] - mini;
            profit = max(profit,newProfit);
            mini = min(mini,arr[i]);
        }
        return profit;
    }
};