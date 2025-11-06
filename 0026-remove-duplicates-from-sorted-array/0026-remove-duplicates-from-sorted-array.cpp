class Solution {
public:
   
    int removeDuplicates(vector<int>& nums) {
        int k =0;
        int n=nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
            while(i+1<n && nums[i] == nums[i+1]){
                i++;
              
            }
        }
       
    
        k = arr.size();
        for(int i=0;i<k;i++){
            nums[i] = arr[i];
        }
        return k;
    }
};