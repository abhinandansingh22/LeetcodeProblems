class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        unordered_map<int,unordered_map<int,bool>> m;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !m[i][j]){
                    count++;
                    add_land(grid,i,j,m);
                }
            }
        }
        return count;
    }
    void add_land(vector<vector<char>>& grid,int i,int j,unordered_map<int,unordered_map<int,bool>> &m){
        if(grid[i][j]=='1' && !m[i][j]){
            m[i][j] = true;
            if(i+1<grid.size()) add_land(grid,i+1,j,m);
            if(i-1>-1) add_land(grid,i-1,j,m);
            if(j+1<grid[0].size()) add_land(grid,i,j+1,m);
            if(j-1>-1) add_land(grid,i,j-1,m);
        }
    }
};