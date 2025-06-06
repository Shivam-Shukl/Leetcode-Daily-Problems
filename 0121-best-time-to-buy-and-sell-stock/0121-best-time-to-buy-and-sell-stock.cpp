class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans = 0;
        int n= arr.size();
        int ele = arr[0];
        for(int i =1;i<n;i++)
        {
            int diff = arr[i] -ele;
            int diff1 = arr[i] - arr[i-1];
            if(diff1 > diff)
            {
                ele = arr[i-1];
                
            }
            diff = max(diff,diff1);
            ans =max(ans,diff);

        }
        return ans;
    }
};