class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int j = 0;
        int ans =0;
        for(auto it = mp.begin();it != mp.end() ;it++){
            int no = it->first;
            int cnt = it->second;

            if(cnt >= 2){
                nums[j] = no;
                nums[j+1] =no;
                j=j+2;
                ans += 2;
            }else{
                nums[j] = no;
                j++;
                ans++;
            }

        }
        return ans;

    }
};