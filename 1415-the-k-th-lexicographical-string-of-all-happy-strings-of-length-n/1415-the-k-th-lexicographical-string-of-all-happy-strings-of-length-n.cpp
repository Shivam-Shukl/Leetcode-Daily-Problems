class Solution {
public:
    void solve(int n, char last, vector<string>& ans, string &s){
        if(n == 0){
            ans.push_back(s);
            return;
        }

        if(last == '#' || last != 'a'){
            s.push_back('a');
            solve(n-1, 'a', ans, s);
            s.pop_back();
        }

        if(last == '#' || last != 'b'){
            s.push_back('b');
            solve(n-1, 'b', ans, s);
            s.pop_back();
        }

        if(last == '#' || last != 'c'){
            s.push_back('c');
            solve(n-1, 'c', ans, s);
            s.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        string s = "";
        
        solve(n, '#', ans, s);

        sort(ans.begin(), ans.end());

        if(k <= ans.size()){
            return ans[k-1];
        }
        return "";
    }
};