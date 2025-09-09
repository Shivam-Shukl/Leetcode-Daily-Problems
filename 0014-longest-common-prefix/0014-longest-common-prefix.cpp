class Solution {
public:
    string check(string &word1, string &word2){
        int i=0,j=0;
        string ans = "";
        while(i<word1.size() && j<word2.size()){

            if(word1[i] == word2[j]){
                ans += word1[i];
                i++,j++;
            }else{
                break;
            }

        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1){
            return strs[0];
        }
        
        string word1 = strs[0],word2 = strs[1];
        
        string ans = check(word1,word2);
     
        if(n<=2){
            return ans;
        }
        else{
            for(int i= 2;i<n;i++){
                word1 = strs[i];
                ans = check(ans,word1);
                
            }
            return ans;
        }
    }
};