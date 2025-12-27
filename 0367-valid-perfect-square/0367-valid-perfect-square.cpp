class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 1,high = num;
        long mid = 0;
        while(lo<=high){
            mid = lo + (high - lo) / 2;
            if(mid*mid == num){  
                return true;
            }else if(mid*mid >  num){
                high = mid -1;
            }else{
                lo = mid+1;
            }
        }
        return false;
    }
};