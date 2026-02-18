class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n){
            int rem = n % 2;
            n = n/2;
            if(prev != -1 && ((prev == 1 && rem == 1) || (prev == 0 && rem == 0))){
                return false;
            }
            prev = rem;
        }
        return true;
    }
};