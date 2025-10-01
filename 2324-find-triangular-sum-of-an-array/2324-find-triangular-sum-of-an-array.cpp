class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp = nums;
        vector<int> temp2;
        while(true){
            if(temp.size() == 1){
                break;
            }
            else{
                int n = temp.size();
                for(int i=0;i<n-1;i++){
                    temp2.push_back((temp[i] + temp[i+1])%10);
                }
                temp = temp2;
                temp2.clear();
            }
        }
        return temp[0];
    }
};