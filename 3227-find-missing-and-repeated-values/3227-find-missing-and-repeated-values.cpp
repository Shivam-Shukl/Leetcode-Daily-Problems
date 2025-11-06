class Solution {
public:
    long long solve(int n){
        long long ans = 0;
        for(int i=1;i<=n*n;i++){
            ans += i;
        }
        return ans;
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n =grid.size();
        long long sum =solve(n);
        long long ans = 0;
        vector<int> res;
        unordered_map<int,int> mp;
        int ele = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(mp[grid[i][j]] != 0){
                    ele = grid[i][j];
                }
                mp[grid[i][j]]++;
                ans += grid[i][j];
            }
        }
        ans -= ele;
        res.push_back(ele);
        res.push_back(sum - ans);
        return res;
    }
};