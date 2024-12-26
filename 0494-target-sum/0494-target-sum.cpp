class Solution {
public:
    int work(int x,int i,int cur,int n,vector<int>& a,vector<vector<int>>&memo){
       if(i==n && cur==x)return 1;
        if(i==n)return 0;
   if(memo[i][cur+1000]!=-1)return memo[i][cur+1000];
    int ans=work(x,i+1,cur-a[i],n,a,memo);
    return memo[i][cur+1000]=ans+=work(x,i+1,cur+a[i],n,a,memo);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
         vector<vector<int>>memo(n+1,vector<int>(2001,-1));
       
        return work(target,0,0,nums.size(),nums,memo);
    }
};