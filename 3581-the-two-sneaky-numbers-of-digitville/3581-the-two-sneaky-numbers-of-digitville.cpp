class Solution {
public:

    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            int no =nums[i];
            if(arr[no] != 0){
                ans.push_back(no);
                arr[no] += 1;
            }else{
                arr[no] += 1;
            }
        }
        return ans;
    }
};