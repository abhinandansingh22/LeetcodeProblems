class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int i = 0;
        if(num==0){
            return 1;
        };
        while(num!=0){
            int bit = !(num&1);
            if (bit == 1){
                ans = ans+ pow(2,i) ;
            };
            i++;
            num=num>>1;
        };
        return ans;
    
    }
};