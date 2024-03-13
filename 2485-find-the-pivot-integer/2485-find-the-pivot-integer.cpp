class Solution {
public:
    int pivotInteger(int n) {
        //We find the sum of total 1 to n using the formula
        int sum=0,pvsum=n*(n+1)/2;
        for(int i=1;i<=n;i++){
            sum+=i;
            if(sum==pvsum-sum+i){
                return i;
            }
        }
        return -1;
    }
};