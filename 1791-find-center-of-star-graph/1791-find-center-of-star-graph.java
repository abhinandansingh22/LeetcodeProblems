class Solution {
    public int findCenter(int[][] edges) {

        Map<Integer, Integer> freqMap = new HashMap<>();
        for(int[] pair: edges){
            int left  = pair[0];
            int right = pair[1];
            int lFreq = freqMap.getOrDefault(left,0);
            int rFreq = freqMap.getOrDefault(right,0);
            lFreq++;
            rFreq++;
            if(lFreq > 1){
                return left;
            }
            if(rFreq > 1){
                return right;
            }
            freqMap.put(left, lFreq);
            freqMap.put(right, rFreq);
        }   
        return -1;
    }
}