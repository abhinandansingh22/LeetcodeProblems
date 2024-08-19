class Solution {
    public int minSteps(int n) {
        if(n==1)
        {
            return 0;
        }
        int res =0, fac =2;
        while(n>1)
        {
            while(n%fac==0)
            {
                res +=fac;
                n /=fac;
                
            }
            fac++;
        }
        return res;
    }
}