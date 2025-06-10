class Solution {
public:
    int solveSpace(string text1,string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        
        for(int i = n-1 ;i>=0 ;i--)
        {
            for(int j= m-1;j>=0; j--)
            {
                int ans = 0;

                if(text1[i] == text2[j])
                {
                    ans = 1 + next[j+1];
                }
                else
                {
                    int fir = next[j];
                    int sec = curr[j+1];
                    ans = max(fir, sec);
                }

                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }

    int longestPalindromeSubseq(string s) {
        string revS = s;
        reverse(s.begin(),s.end());
        return solveSpace(s,revS);
    }
};
