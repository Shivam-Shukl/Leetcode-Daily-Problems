class Solution {
public:
    int pow(int base , int exp){
        int ans = 1;
        for(int i=0;i<exp;i++){
            ans = ans*base;
        }
        return ans;
    }
    int smallestNumber(int n) {
        // 1 , 3 , 7, 15, 2^n -1  n is from 1 
        int i = 1;
        while(true){
            int no = pow(2,i)-1;
            i++;
            if(no >= n){
                return no;
                break;
            }
        }
    }
};