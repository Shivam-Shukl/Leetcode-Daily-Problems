class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        ans = numBottles;
        int empty= numBottles;
        numBottles = 0;
        while(empty >= numExchange){
            while(empty>= numExchange){
                empty = empty - numExchange;
                numBottles++;
                numExchange++;
            }
         
            ans += numBottles;
            empty += numBottles;
            numBottles = 0;
        }
        return ans;
    }
};