class Solution {
public:
    // to toggle the row
    void rowToggle(vector<vector<int>> &grid,int row){
        
        for(int j=0;j<grid[row].size();j++){
                grid[row][j]^=1; 
            }
    }
    // to toggle the column
    void colToggle(vector<vector<int>> &grid,int col){
        for(int i=0;i<grid.size();i++){
            grid[i][col]^=1;
        }
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==0){
                rowToggle(grid,i);
            }
        }
        for(int i=1;i<grid[0].size();i++){
            unordered_map<int,int> mp;
            for(int j=0;j<grid.size();j++){
            mp[grid[j][i]]++;
            }
            if(mp[0]>mp[1]) colToggle(grid,i);
            mp.clear();
        }
        
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int size=grid[0].size()-1;
            for(int j=0;j<grid[0].size();j++){
                ans+=grid[i][j]*pow(2,size);
                size--;
            }
        }
        return ans;
    }
};