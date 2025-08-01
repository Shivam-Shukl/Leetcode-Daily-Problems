class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> temp(i,1);
            if(i>=3){
                for(int j = 1;j<i-1;j++){
                  
                    temp[j] = prev[j-1]+prev[j];
                }
            }
            prev = temp;
            ans.push_back(temp);
        }
        return ans;
    }
};