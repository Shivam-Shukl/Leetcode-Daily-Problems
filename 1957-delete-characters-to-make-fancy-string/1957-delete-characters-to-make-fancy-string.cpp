class Solution {
public:
    string makeFancyString(string s) {
        
        int cnt =1;
        string ans = "";
        ans+= s[0];
        for(int i=1;i<s.size();i++)
        {
           
            if(s[i] == s[i-1])
            {
                cnt++;
            }else{
                cnt = 1;
            }
            if(cnt <=2)
            {
                ans += s[i];
            }
        }
        return ans;
    }
};