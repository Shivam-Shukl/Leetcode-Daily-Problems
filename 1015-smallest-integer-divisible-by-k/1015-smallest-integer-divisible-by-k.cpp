class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ans = -1;
        if((k%2 == 0) || (k%5== 0) ){
        
        }else{
            int rem = 0;
            int cnt = 0;
            while(cnt < k){
                rem = (rem* 10 + 1) %k;
                cnt++;
                if(rem == 0){
                    ans = cnt;
                    break;
                }
            }
        }
        return ans;
    }
};