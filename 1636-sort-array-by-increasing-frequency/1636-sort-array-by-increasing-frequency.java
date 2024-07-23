class Solution {
    public int[] frequencySort(int[] nums) {
       HashMap<Integer, Integer> map = new HashMap<>();
       for(int num: nums){
        map.put(num, map.getOrDefault(num, 0)+1);
       } 
       List<Map.Entry<Integer, Integer>> list = new LinkedList<>(map.entrySet());
       list.sort((a, b) -> {
            int freqCompare = a.getValue().compareTo(b.getValue());
            if (freqCompare != 0) {
                return freqCompare;
            } else {
                return b.getKey().compareTo(a.getKey());
            }
        });
       int[] result = new int[nums.length];
        int index = 0;
        for (Map.Entry<Integer, Integer> entry : list) {
            int number = entry.getKey();
            int frequency = entry.getValue();
            for (int i = 0; i < frequency; i++) {
                result[index++] = number;
            }
        }

        return result;
    }
}