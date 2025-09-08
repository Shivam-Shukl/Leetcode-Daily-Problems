class Solution {
public:
    int value(char ch){
        if(ch == 'I')
        {
            return 1;
        }else if(ch == 'V'){
            return 5;
        }else if(ch == 'X'){
            return 10;
        }else if(ch == 'L'){
            return 50;
        }else if(ch == 'C'){
            return 100;
        }else if(ch == 'D'){
            return 500;
        }else{
            return 1000;
        }
    }

    int romanToInt(string s) {
        
        int n = s.size();
        int i =0;
        int ans = 0;
        while(i<n){
            int v1 = value(s[i]);
            int v2 = 0;
            if(i+1 <n){
                v2 = value(s[i+1]);
            }
            if(v2 > v1){
                v2 = v2 - v1;
                ans += v2;
                i = i+2;
            }else{
                ans += v1;
                i++;
            }
        }
        return ans;
    }
};