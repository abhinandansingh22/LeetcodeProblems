class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        int n = nums.length;
        int max = 0;

        Arrays.sort(nums);

        for(int num:nums){
            max = Math.max(max, num);
        }

        int i = 0;
        int j = max-1;

        while(i<j){
            int mid = (i+j)/2; //mid difference
            //calculate no of pairs differences les than equal to mid

            int left = 0;
            int right = 0;

            int count = 0;

            while(right<n){
                int abs = nums[right] - nums[left];

                if(abs<=mid){
                    count += right-left;
                    right++;
                } else {
                    left++;
                }
            }

            if(count<k){ 
                i = mid+1;
            } else {
                j = mid;
            }
        }

        return i;
    }
}