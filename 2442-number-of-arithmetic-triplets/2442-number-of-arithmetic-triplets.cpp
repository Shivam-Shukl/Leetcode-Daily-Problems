class Solution {
public:
    int arithmeticTriplets(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int cnt = 0;
        for(int j = 1;j<n;j++){
            if(mp.find(arr[j] - diff) != mp.end() && mp.find(arr[j] + diff) != mp.end()){
                cnt++;
            }

        }
        return cnt;
    }
};