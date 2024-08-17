class Solution {
    public long maxPoints(int[][] points) {
        int m = points.length, n = points[0].length;
        long[][] dp = new long[m][n];

        for (int j = 0; j < n; ++j) dp[0][j] = points[0][j];

        for (int i = 1; i < m; ++i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i - 1][j] = Math.max(dp[i - 1][j], dp[i - 1][j + 1] - 1);
            }

            long prefix = 0;
            for (int j = 0; j < n; ++j) {
                dp[i][j] = points[i][j] + Math.max(prefix, dp[i - 1][j]);
                prefix = Math.max(prefix, dp[i - 1][j]) - 1;
            }
        }

        long max = Long.MIN_VALUE;
        long temp = 234;
        for (int j = 0; j < n; ++j) {
            max = Math.max(max, dp[m - 1][j]);
        }

        return max;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] points = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
        System.out.println(sol.maxPoints(points));  // Output should be 9
    }
}
