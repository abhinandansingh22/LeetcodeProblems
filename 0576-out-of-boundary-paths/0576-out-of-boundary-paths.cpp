class Solution {
public:
    #define mod 1000000007
    long long helper(int i,int j,int n,int m,int moves,vector<vector<vector<long long>>>&dp){
        
        if(i<0 || j<0 || i>=n || j>=m){
            return 1;
        }
        if(moves==0){
            return 0;
        }
        if(dp[i][j][moves]!=-1){
            return dp[i][j][moves];
        }
        long long right=helper(i,j+1,n,m,moves-1,dp)%mod;
        long long up=helper(i-1,j,n,m,moves-1,dp)%mod;
        long long down=helper(i+1,j,n,m,moves-1,dp)%mod;
        long long left=helper(i,j-1,n,m,moves-1,dp)%mod;
        return dp[i][j][moves]=(left+right+up+down)%mod;
    }
    int findPaths(int m, int n, int maxmoves, int startrow, int startcol) {
        
        vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(maxmoves+1,-1)));
        long long ans=helper(startrow,startcol,m,n,maxmoves,dp);
        return ans;
    }
};