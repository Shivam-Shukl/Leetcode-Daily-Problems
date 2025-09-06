class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        int jump = nums[0];
        int curr = 0;
        while(jump != 0 && ind != n-1){
            int maxi = 0;
            
            for(int i= curr+1 ;i <n && i<= curr + jump ;i++){
                if(i == n-1){
                    ind = n-1;
                    break;
                }
                int sum = nums[i] + i;
                if(maxi <= sum){
                    maxi = sum;
                    ind = i;
                }
            }
            
            curr = ind;
            cout<<curr<<" ";
            jump = nums[ind];
            cout<<"jump"<<jump<<" ";
        }

        return ind == n-1;
    }
};