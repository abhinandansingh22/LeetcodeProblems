class Solution {
    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        int size = n * n * 4; // each cell can be divided into 4 triangles
        UnionFind uf = new UnionFind(size);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i].charAt(j);
                int base = (i * n + j) * 4;
                
                // Merge regions within the cell
                if (c == '/') {
                    uf.union(base + 0, base + 3);
                    uf.union(base + 1, base + 2);
                } else if (c == '\\') {
                    uf.union(base + 0, base + 1);
                    uf.union(base + 2, base + 3);
                } else {
                    uf.union(base + 0, base + 1);
                    uf.union(base + 1, base + 2);
                    uf.union(base + 2, base + 3);
                }
                
                // Merge regions with neighboring cells
                if (i < n - 1) { // connect bottom cell
                    uf.union(base + 2, base + 4 * n + 0);
                }
                if (j < n - 1) { // connect right cell
                    uf.union(base + 1, base + 4 + 3);
                }
            }
        }
        
        return uf.count();
    }
}

class UnionFind {
    private int[] parent;
    private int[] rank;
    private int count;
    
    public UnionFind(int size) {
        parent = new int[size];
        rank = new int[size];
        count = size;
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }
    
    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }
    
    public int count() {
        return count;
    }
}
