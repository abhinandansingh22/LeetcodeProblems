class Solution {
     private final int[] delRow= {1,-1,0,0};
     private final int[] delCol= {0,0,-1,1};
 private void dfs(int[][] grid,int[][] vis, int n,int m, int row,int col)
    {
        if(row < 0 || row >= n || col < 0 || col >= m || vis[row][col] == 1 || grid[row][col] == 0)
        {
            return;
        }

        vis[row][col]=1;

        for(int i=0; i<4; i++)
        {
            int nRow= row + delRow[i];
            int nCol= col + delCol[i];
            
             if(nRow >= 0 &&  nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0)
             {
                dfs(grid, vis, n,m ,nRow,nCol);
             }

        }
    }

    private int Cislands(int[][] grid, int n, int m){
        
        int island = 0;
        int[][] vis= new int[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    island++;
                    dfs(grid, vis,n, m, i, j);
                }
            }
        }
        
        return island;
      
    }

    public int minDays(int[][] grid) {
        
        int n = grid.length;
        int m= grid[0].length;
        int[][] vis = new int[n][m];

        int islands = Cislands(grid, n, m);
       
        if(islands != 1) return 0;

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                  grid[i][j] = 0;
                 int count=  Cislands(grid, n, m);
                 if(count != 1) return 1;
                 grid[i][j]=1;
                }
            }
        }

        return 2;
        
    }
}