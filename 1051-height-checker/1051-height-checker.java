class Solution {
    private static final int[] arr = new int[101];
    public int heightChecker(int[] heights) {
        for (int num : heights) arr[num]++;
        int result = 0;
        for (int i = 0, j = 0; i < heights.length; result += heights[i] == j ? 0 : 1, i++, arr[j]--)
            for ( ; arr[j] == 0; j++);
        return result;
    }
}