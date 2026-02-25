class Solution {
public:
    int help(int n){
        int ans = 0;
        while(n){
            int rem = n % 2;
            n = n / 2;
            if (rem == 1) {
                ans += 1;
            }
        }
        return ans;
    }

    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        vector<pair<int,int>> v;
        vector<int> ans;

        for(int i = 0; i < arr.size(); i++){
            v.push_back({help(arr[i]), arr[i]});
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < arr.size(); i++){
            ans.push_back(v[i].second);  
        }

        return ans;
    }
};