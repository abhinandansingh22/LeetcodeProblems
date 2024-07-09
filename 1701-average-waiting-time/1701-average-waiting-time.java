class Solution {
    public double averageWaitingTime(int[][] customers) {
        double waitingTime = 0;
        double time = 0;
        for (int[] customer: customers) {
            time = Math.max(time, customer[0]);
            time += customer[1];
            waitingTime += time - customer[0];
        }

        return waitingTime / customers.length;
    }
}