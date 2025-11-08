class Solution {
public:
    void solve(vector<char>& s,vector<char>& temp){
        if(s.size() == 0){
            return;
        }
        char ch = s.back();
        s.pop_back();
        temp.push_back(ch);
        solve(s,temp);
        
    }
    void reverseString(vector<char>& s) {
        vector<char> temp;
        solve(s,temp);
        s = temp;
    }
};