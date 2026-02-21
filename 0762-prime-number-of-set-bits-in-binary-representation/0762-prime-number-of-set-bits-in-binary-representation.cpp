class Solution {
public:
    int helper(int val){
        set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int cnt= 0;
        while(val){
            int rem = val % 2;
            val = val / 2;
            if(rem == 1) cnt++;
        }
        if(st.contains(cnt)){
            return 1;
        }else{
            return 0;
        }
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left ;i<= right;i++){
            ans += helper(i);
        }
        return ans;
    }
};