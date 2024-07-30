class Solution {
    public int dynamic_a(String s, int[] dp, int idx) {
        // Base case: If idx is out of bounds, return 0
        if (idx >= s.length()) {
            return 0;
        }
        // If already computed, return the stored value
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int temp = 0;
        // Check if the current character is 'a'
        if (s.charAt(idx) == 'a') {
            temp = dynamic_a(s, dp, idx + 1) + 1;
        } else {
            temp = dynamic_a(s, dp, idx + 1);
        }
        // Store the result in dp array and return it
        dp[idx] = temp;
        return temp;
    }

    public int dynamic_b(String s, int[] dp, int idx) {
        // Base case: If idx is out of bounds, return 0
        if (idx < 0) {
            return 0;
        }
        // If already computed, return the stored value
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int temp = 0;
        // Check if the current character is 'b'
        if (s.charAt(idx) == 'b') {
            temp = dynamic_b(s, dp, idx - 1) + 1;
        } else {
            temp = dynamic_b(s, dp, idx - 1);
        }
        // Store the result in dp array and return it
        dp[idx] = temp;
        return temp;
    }

    public int minimumDeletions(String s) {
        int len = s.length();
        int[] dpa = new int[len];
        int[] dpb = new int[len];
        Arrays.fill(dpa, -1);
        Arrays.fill(dpb, -1);
        dynamic_a(s, dpa, 0);
        dynamic_b(s, dpb, len - 1);
        int result = 1000000;
        result = Math.min(dpa[0], dpb[len - 1]);
        for (int i = 1; i < dpb.length - 1; i++){
            result = Math.min(result, dpa[i] + dpb[i - 1]);
        }


        return result;
    }
}