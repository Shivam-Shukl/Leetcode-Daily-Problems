class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int curr = INT_MAX;
        int ans = 0;
        int n = nums.size();


        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                for(int k = j+1;k<n;k++){

                    int sum = nums[i] + nums[j] + nums[k];
                    int dif = 0;
                    if(target < sum){
                        dif = sum - target;
                    }else{
                        dif =target - sum;
                    }
                 
                    if(dif < curr){
                        curr = dif;
                        ans = sum;
                    }
                }
            }
            
        }
        return ans;
    }
};