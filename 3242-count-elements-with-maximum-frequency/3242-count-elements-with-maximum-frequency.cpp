class Solution {
public:
    
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(101,0);
        int maxi = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
            maxi = max(maxi, arr[nums[i]]);
        }
      
        for(int i=0;i<101;i++){
            if(arr[i] == maxi){
                cnt += maxi;
            }
        }
        return cnt;
    }
};