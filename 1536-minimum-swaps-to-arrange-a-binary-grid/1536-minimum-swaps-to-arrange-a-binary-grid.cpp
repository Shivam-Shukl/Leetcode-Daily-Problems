class Solution {
public:
    int solve(vector<int> &v){
        int stp = 0;
        int n =v.size();
        
        for(int i =0;i<n;i++){
            int val = n-i-1;
            if(v[i] < val){
                int j= i+1;
                while(j<n && v[j] < val){
                    j++;
                }
                if(j >= n){
                    return -1;
                }else{
                    for(int k = j ;k > i ;k--){
                        swap(v[k],v[k-1]);
                        stp++;
                    }
                }
            }
        }
        return stp;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n,0);
        for(int i =0;i<n;i++){
            int cnt = 0;
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    cnt = 0;
                }else{
                    cnt++;
                }
            }
            v[i] = cnt;
        }
     
        return solve(v);
    }
};