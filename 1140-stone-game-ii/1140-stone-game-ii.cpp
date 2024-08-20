class Solution {
public:
    int dp[101][201][2];
    int solve(int ind,vector<int>&piles,int m,int alice){
        if(ind >= piles.size()) return 0;
        if(dp[ind][m][alice]!=-1) return dp[ind][m][alice];
        int mini = INT_MAX;
        int maxi = INT_MIN;
        long long tsum = 0;
        for(int i = ind;i < ind + (2*m) && i < piles.size() ;i++){
            int cost = piles[i];
            if(!alice) cost *= -1;
            tsum += cost;
            int res = tsum + solve(i+1,piles,max(m,i-ind+1),!alice);
            mini = min(mini,res);
            maxi = max(maxi,res);
        }
        return dp[ind][m][alice] = alice ? maxi : mini;
    }
    
    int stoneGameII(vector<int>& piles) {
        int sum = 0;
        memset(dp,-1,sizeof dp);
        for(auto i:piles)
            sum += i;
        return (solve(0,piles,1,1)+sum)/2;
    }
};