class Solution {
public:
    // cnt -> it will take count of no of opening brakets.
    // curr will take count curr no of opening braket. 
    // when curr will 0 i will add to the vector
    // 
    void solve(int n , vector<string>& ans, string& val,int cnt,int curr){

        if(cnt == n && curr == 0){
            ans.push_back(val);
            return;
        }
        // add oepning brakets only when we have to cnt less than 
        if(cnt < n){
            val.push_back('(');
            solve(n, ans, val, cnt +1, curr + 1);
            val.pop_back();
        }
        
        if(curr > 0){
            val.push_back(')');
            solve(n,ans,val,cnt,curr -1);
            val.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string val;
        solve(n,ans,val,0,0);
        return ans;

    }

};