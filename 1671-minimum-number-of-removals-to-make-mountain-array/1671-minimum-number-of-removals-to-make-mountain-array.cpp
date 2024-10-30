class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0),dp2(n,0);
        //Increasing subsequence
        for(int i=1;i<dp.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        //Decreasing subsequence
        for(int i=dp.size()-2;i>=0;i--){
            for(int j=dp.size()-1;j>i;j--){
                if(nums[i]>nums[j])
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
        int max1=0;
        for(int i=0;i<n;i++){
            if(dp[i]!=0 && dp2[i]!=0)//neither of them must be zero
            max1=max(max1,dp[i]+dp2[i]+1);
        }
        return n-max1;
    }
};