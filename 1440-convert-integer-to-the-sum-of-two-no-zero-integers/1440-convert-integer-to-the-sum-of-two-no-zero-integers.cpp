class Solution {
public:
    bool iscond(int a, int b){
        string s1 = to_string(a);
        string s2 = to_string(b);;
        for(int i=0;i<s1.size();i++){
            if(s1[i] == '0'){
                return false;
            }
        }
        for(int i=0;i<s2.size();i++){
            if(s2[i] == '0'){
                return false;
            }
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++){
            int a = i;
            int b = n-i;
            if(a > 0 && b> 0 && iscond(a,b)){
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
        }
        
        return ans;
    }
};