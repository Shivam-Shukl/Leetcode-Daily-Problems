class Solution {
public:
    int bitwiseComplement(int n) {
        if(n== 0) return 1;
        string s;
        while(n){
            s.push_back(n%2 + '0');
            n = n/2;
        }
        reverse(s.begin(),s.end());
        cout<<s;
        for(int i =0;i<s.size();i++){
            if(s[i] == '0'){
                s[i] = '1';
            }else{
                s[i] = '0';
            }
        }
        int ans = 0;
        int mul = 1;
        for(int i = s.size() -1;i>= 0;i--){
            if(s[i] == '1') ans += mul;
            mul = mul * 2;
        }
        return ans;

    }
};