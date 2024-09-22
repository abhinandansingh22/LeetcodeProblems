class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1; // Start from the first number
        k--; // Decrement k because we count the first number as 1

        while (k > 0) {
            int steps = calculateSteps(n, curr, curr + 1);
            if (steps <= k) {
                // If the number of steps is less than or equal to k, move to the next prefix
                curr++;
                k -= steps;
            } else {
                // Otherwise, move down one level in the current prefix
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }

private:
    // Function to calculate the steps between two numbers within the bounds of n
    int calculateSteps(int n, long curr, long next) {
        int steps = 0;
        while (curr <= n) {
            steps += min((long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};
