class Solution {

    public int[] sortJumbled(int[] mapping, int[] nums) {
        // Create a list of pairs (mapped value, original index)
        List<Pair> pairs = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int mappedValue = mapValue(nums[i], mapping);
            pairs.add(new Pair(mappedValue, nums[i]));
        }

        // Sort the pairs based on the mapped value
        pairs.sort(Comparator.comparingInt(pair -> pair.mappedValue));

        // Extract the sorted original values
        int[] sortedNums = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            sortedNums[i] = pairs.get(i).originalValue;
        }

        return sortedNums;
    }

    // Method to convert a number based on the mapping
    private int mapValue(int num, int[] mapping) {
        StringBuilder mapped = new StringBuilder();
        String numStr = String.valueOf(num);
        for (char digit : numStr.toCharArray()) {
            mapped.append(mapping[digit - '0']);
        }
        return Integer.parseInt(mapped.toString());
    }

    // Helper class to store mapped value and original value
    private static class Pair {
        int mappedValue;
        int originalValue;

        Pair(int mappedValue, int originalValue) {
            this.mappedValue = mappedValue;
            this.originalValue = originalValue;
        }
    }
}