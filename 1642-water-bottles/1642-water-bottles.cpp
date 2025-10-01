class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles =numBottles;
        int cnt = numBottles;
        while(true){
            if(emptyBottles < numExchange){
                break;
            }else{
                int no= emptyBottles/numExchange;
                emptyBottles = emptyBottles % numExchange;
                emptyBottles += no;
                cnt += no;
            }
        }
        return cnt;
    }
};