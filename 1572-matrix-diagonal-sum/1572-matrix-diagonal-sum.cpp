class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum =0;
        map<pair<int,int>,bool> visited;

        int n = mat.size();
        int i =0,j=0;
        while(i<n && j<n)
        {
            int ele = mat[i][j];
            sum += ele;
            visited[{i,j}] = true;
            i++,j++;
        }
        i = n-1,j=0;
        while(i>=0 && j<n)
        {
            if(!visited[{i,j}])
            {
                int ele= mat[i][j];
                sum += ele;
            }
            i--,j++;
        }
        return sum;
    }
};