class Solution {
public:
    int gcd(int a, int b){
        int ans= (b== 0) ? a :  gcd(b,a%b);
        return ans;
    }
    int findGCD(vector<int>& nums) {
        int ans =0;
        int maxi = 0, mini = 1000,n = nums.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }
      
        return gcd(maxi,mini);
    }
};