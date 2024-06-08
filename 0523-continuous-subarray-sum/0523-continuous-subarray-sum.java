class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int sum = 0;
        for(int i=0; i<nums.length; i++){
            sum += nums[i];
            int sumMod = sum%k;
            if(map.containsKey(sumMod)){
                int numIdx = map.get(sumMod);
                if(i-numIdx >= 2){
                    return true;
                }
            }else{
                map.put(sumMod, i);
            }
        }
        return false;
    }
}