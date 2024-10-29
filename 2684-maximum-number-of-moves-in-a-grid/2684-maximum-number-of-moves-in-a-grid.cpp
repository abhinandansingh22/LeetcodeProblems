class Solution {
public:
    bool isvalid(int row, int col, int val, vector<vector<int>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] > val;
    }

    int solve(int row, int col, vector<vector<int>>& grid,vector<vector<int>>&dp) {
       
        if (col >= grid[0].size()) return 0;

        int up_left = 0, right = 0, dw_right = 0;
        if(dp[row][col]!=-1){return dp[row][col];}
        if (isvalid(row - 1, col + 1, grid[row][col], grid)) {
            up_left = 1 + solve(row - 1, col + 1, grid,dp);
        }
        
 
        if (isvalid(row, col + 1, grid[row][col], grid)) {
            right = 1 + solve(row, col + 1, grid,dp);
        }
        
    
        if (isvalid(row + 1, col + 1, grid[row][col], grid)) {
            dw_right = 1 + solve(row + 1, col + 1, grid,dp);
        }
        
        return dp[row][col]= max({up_left, right, dw_right});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for (int i = 0; i < grid.size(); i++) {
            ans = max(ans, solve(i, 0, grid,dp));  
        }
        return ans;
    }
};
