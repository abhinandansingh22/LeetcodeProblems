class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> onePos;
        for(int i=0; i<n; i++){
            if(nums[i]) onePos.push_back(i);
        }
         int m = onePos.size();
         int res = 0;
        if(goal == 0){
            if( m == 0) return n*(n+1)/2;
            
            int  prev = 0, k;
            for(int j=0; j<m; j++){
                k = onePos[j] - (j > 0 ? onePos[j-1] : -1) - 1;

               res += k*(k+1)/2;
            }
            k = n - onePos[m-1] - 1;
            res += k*(k+1)/2;
        }
        else{
           int i = 0, j = goal -1;
           while(j < m){
               int l = onePos[i] - (i>0 ? onePos[i-1] : -1);
               int r = (j+1 < m ? onePos[j+1] : n) - onePos[j];

               res += l*r;

               i++; j++;
           }
        }
        return res;
    }
};