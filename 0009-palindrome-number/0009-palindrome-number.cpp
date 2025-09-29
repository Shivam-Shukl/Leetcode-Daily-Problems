class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 ) return false;
   
        long long  rev = 0;
        int val = x;
        while(val){
            rev = rev*10 + val % 10;
            val = val /10;
            
        }
        return rev == x;
    }
};