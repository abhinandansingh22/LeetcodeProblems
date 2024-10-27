class Solution {
    private:
    int solve(int row,int col,vector<vector<int>>&matrix, vector<vector<int>>&dp){
        // Base Case:
        if(row >= matrix.size() or col>= matrix[0].size()){
            //We are out of bounds:
            return 0;
        }
        //No need to search if matrix[row][col] == 0;
        if(matrix[row][col] == 0){return 0;}

        if(dp[row][col]!=-1) {return dp[row][col];}
        
        int right = solve(row ,col+1,matrix,dp);
        int down = solve(row+1,col,matrix,dp);
        int diagonal = solve(row+1,col+1,matrix,dp);


        return dp[row][col] = 1 + min(right,min(down,diagonal));
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n = matrix.size();
        int m = matrix[0].size();

        int result = 0;
        vector<vector<int>>dp(n,vector<int>(m+1,0));

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j] == 1){
        //             result += solve(i,j,matrix,dp);
        //         }
        //     }
        // }
        
        // return result;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                //Base case:
                if(i==0 or j==0){
                    dp[i][j] = (matrix[i][j] == 1? 1:0);
                }
                else if(matrix[i][j] == 1){
                    dp[i][j] =1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    // result += dp[i][j];
                }
                result += dp[i][j];
            }
        }

        return result;


    }
};