class Solution {
public:
    int solve(vector<int>& arr,int k){
        int n= arr.size();
        vector<int> p(k+1,0),s(k+1,0);
        for(int i =0;i<k;i++){
            p[i+1] = p[i] + arr[i];
            
        }
        int j = 0;
        for(int i = n-1;i>=n-k ;i--){
            s[j+1] = s[j] + arr[i];
            j++;
        }
        int ans = 0;
        for(int i = 0 ;i<=k;i++){
            ans = max(s[i]+p[k-i],ans);
           
        }
        return ans;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        return solve(cardPoints,k);
    }
};