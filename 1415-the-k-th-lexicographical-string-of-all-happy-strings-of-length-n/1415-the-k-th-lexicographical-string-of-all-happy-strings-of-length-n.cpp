class Solution {
public:
    void solve(int n,vector<string>& ans,string &s){
        if(n== 0){
            ans.push_back(s);
            return;
        }

        if(s.size() == 0 ||(s.size() >= 0 && s.back()  != 'a')){
            s.push_back('a');
            solve(n-1,ans,s);
            s.pop_back();
        }

        if(s.size() == 0 ||(s.size() >= 0 && s.back()  != 'b')){
            s.push_back('b');
            solve(n-1,ans,s);
            s.pop_back();
        }

        if(s.size() == 0 ||(s.size() >= 0 && s.back()  != 'c')){
            s.push_back('c');
            solve(n-1,ans,s);
            s.pop_back();
        }

    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string s = "";
        solve(n,ans,s);
        sort(ans.begin(),ans.end());
        // for(int i =0;i<ans.size();i++) cout<<ans[i]<<" ";
        // cout<<endl;
        if(k <= ans.size() )
            return ans[k-1];
        else 
            return "";
    }
};