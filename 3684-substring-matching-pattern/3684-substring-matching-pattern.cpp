class Solution {
public:
    bool hasMatch(string s, string p) {
        // what your'e thinking of i have one thing that i will traverse and
        // will match first part and then skip for * and than start again
        // matching.
        bool ans = false;
        int i = 0; //
        int j = 0; //  for patern.
        int n = s.size(), m = p.size();

        while (i < n && j < m) {
            if (p[j] == '*') {
                j++;
                break;
            }
            
            if (s[i] == p[j]) {
               
                int ind =0;
                int pre = i;
                while (i < n && j < m && s[i] == p[j]) {
                 
                    i++, j++;
                }
                
                if (p[j] == '*') {
                    j++;
                    break;
                } else {
                    j = 0;
                    i = pre+1;
                }
            }else {
              
                i++;
            }
        }
        int ind = j;
     
        while (i < n && j < m) {
            if (s[i] == p[j]) {
                int pre = i;
                while (i < n && j < m && s[i] == p[j]) {
                    i++, j++;
                   
                }
                if (j == m) {
                    ans = true;
                    
                } else {
                    j = ind;
                    i = pre+1;
                }
            } else {
                i++;
            }
        }
        return j == m;
    }
};