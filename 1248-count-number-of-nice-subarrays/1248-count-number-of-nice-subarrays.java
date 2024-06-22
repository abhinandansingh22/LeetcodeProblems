class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
       return count(nums,k+1) - count(nums,k);
    }
    int count(int[] nums, int k){
        int n = nums.length;
        int start=0,end=0;
        int answer=0;
        int odd=0;
        while(end<n){

            if(nums[end]%2!=0) odd++;

            while(odd>=k){
                if(nums[start]%2!=0) odd--;
                start++;
            }

            if(odd<k) answer+= end-start+1;
            end++;
        }
        return answer;
    }
}