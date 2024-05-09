class Solution {
public:
    long long maximumHappinessSum(vector<int>& H, int k) {
        sort(H.rbegin(),H.rend());
        long long sum = H[0];
        int i=1;
        int count = 0;
        k = k-1;
        while(k-- && i<H.size()){
            count++;
            if(H[i]-count > 0){
                sum += H[i] - count;
            }
            else{
                break;
            }
            i++;
        }
        return sum;
    }
};