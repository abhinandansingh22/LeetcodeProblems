class Solution {
public:
    bool judgeSquareSum(int c) {

        if(c==1)
        {
            return true;
        }
        long i=0;
        long j=int(sqrt(c));
        while(i<=j)
        { 
            long a = i*i + j*j;
            if(a==c)
            {
                return true;
            }
            else if(a>c)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        

        return false;
        
    }
};