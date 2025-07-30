class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        int maxi =0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,arr[i]);
        }

        int ans =0;
        
        int current_streak = 0;
        for(int i=0;i<n;i++)
        {

            if(arr[i] == maxi)
                current_streak++;
            else{
                current_streak = 0;
            }
            ans = max(ans,current_streak);
        }
        return ans;
    }
};