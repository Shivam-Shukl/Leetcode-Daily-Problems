class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& que) {
        vector<vector<int>> mat(n,vector<int>(n,0));
    
        for(int i = 0;i<que.size() ;i++){
            int row1 = que[i][0],col1 = que[i][1],row2 = que[i][2],col2= que[i][3];
            for(int row = row1;row<=row2;row++){
                for(int col = col1 ;col<= col2 ;col++){
                    mat[row][col] += 1;
                }
            }
        }
        return mat;
    }
};