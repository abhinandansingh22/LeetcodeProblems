class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int result = 0;
        LinkedList<Integer> queue = new LinkedList<>();
        for(int i = 0; i<nums.length; i++){

            if(queue.size()>0 && i>=(queue.getFirst()+k)){
                queue.removeFirst();
            }
           if(queue.size()%2==0 && nums[i]==1){
                continue;
           }

           if(queue.size()%2==1&& nums[i]==0){
                nums[i]=1;
                continue;
           }

           if(queue.size()%2==0 && nums[i]==0){
                
                if(i+k-1<nums.length){
                nums[i]=1;

                    result++;
                    queue.addLast(i);
                }else{
                    return -1;
                }
                continue;
           }

           if(queue.size()%2==1 && nums[i]==1){
                if(i+k-1<nums.length){
                    result++;
                    queue.addLast(i);
                }else{
                    return -1;
                }
           }


        }


    

        return result;
    }
}