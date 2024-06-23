class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int n=nums.length;
        Deque<Integer> dec=new LinkedList<>();
         Deque<Integer> inc=new LinkedList<>();
         int ans=0;
         int left=0;
         for(int right=0;right<n;++right){
            int num=nums[right];
            while(!dec.isEmpty() && num>dec.peekLast()){
                dec.pollLast();
            }
            dec.addLast(num);
            while(!inc.isEmpty()  && num<inc.peekLast()){
                inc.pollLast();
            }
            inc.addLast(num);

            while(dec.peekFirst()-inc.peekFirst() >limit){
                if (dec.peekFirst() == nums[left]) {
                    dec.pollFirst();
                }
                if (inc.peekFirst() == nums[left]) {
                    inc.pollFirst();
                }
                ++left;
            }
            ans=Math.max(ans,right-left+1);
         }
         return ans;

    }
}