import java.util.Arrays;

class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.length;
        int[][] jobs = new int[n][2];
        
        // Pairing difficulty and profit
        for (int i = 0; i < n; i++) {
            jobs[i][0] = difficulty[i];
            jobs[i][1] = profit[i];
        }
        
        // Sort jobs by difficulty
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        
        // Sort worker by their ability
        Arrays.sort(worker);
        
        int maxProfit = 0;
        int jobIndex = 0;
        int currentMaxProfit = 0;
        
        // Iterate through each worker's ability
        for (int ability : worker) {
            // Update the current maximum profit that a worker with this ability can get
            while (jobIndex < n && jobs[jobIndex][0] <= ability) {
                currentMaxProfit = Math.max(currentMaxProfit, jobs[jobIndex][1]);
                jobIndex++;
            }
            maxProfit += currentMaxProfit;
        }
        
        return maxProfit;
    }
}