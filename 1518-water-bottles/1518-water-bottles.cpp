class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int extra;
        while(numBottles >= 0){
            extra = numBottles/numExchange;
            if(extra ==0)
                break;
            ans += extra;
            numBottles = numBottles%numExchange + extra;
        }
        return ans;
    }
};