class Solution {
    private int getSum(int[][] grid, int i, int j, int xDir, int yDir) {
        int sum = 0;
        for (int k = i, l = j, times = 0; times < 3; k += xDir, l += yDir, times++) {
            //System.out.println(k + " " + l + " " + sum);
            sum += grid[k][l];
        }
        return sum;
    }

    private boolean checkDistinct(int[][] grid, int i, int j) {
        Set<Integer> seen = new HashSet<>();
        for (int k = i; k < i + 3; k++) {
            for (int l = j; l < j + 3; l++) {
                if (seen.contains(grid[k][l]) || grid[k][l] > 9
                    || grid[k][l] < 1) return false;
                seen.add(grid[k][l]);
            }
        }
        return seen.size() == 9;
    }

    private boolean checkIsMagic(int[][] grid, int i, int j) {
        if (checkDistinct(grid, i, j)) {
            int rowSum = getSum(grid, i, j, 0, 1);
            for (int x = 1; x < 3; x++) {
                if (getSum(grid, i + x, j, 0, 1) != rowSum) return false;
            }
            for (int x = 0; x < 3; x++) {
                if (getSum(grid, i, j + x, 1, 0) != rowSum) return false;
            }
            if (getSum(grid, i, j, 1, 1) != rowSum
                || getSum(grid, i + 2, j + 2, -1, -1) != rowSum) return false;
            return true;
        }
        return false;
    }
    public int numMagicSquaresInside(int[][] grid) {
        int cnt = 0;
        for (int i = 0; i < grid.length - 2; i++) {
            for (int j = 0; j < grid[0].length - 2; j++) {
                if (checkIsMagic(grid, i, j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}