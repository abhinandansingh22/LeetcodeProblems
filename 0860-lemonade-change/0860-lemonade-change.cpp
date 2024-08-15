class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0;
        int calc = 0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
                five++;
            else if(bills[i]==10)
            {
                calc++;
                ten++;
                five--;
            }
            else
            {
                twenty++;
                five--;
                if(ten)
                    ten--;
                else
                    five-=2;
            }
            if(five<0 || ten<0 || twenty<0)
                return 0;
        }
        
        return 1;
    }
};