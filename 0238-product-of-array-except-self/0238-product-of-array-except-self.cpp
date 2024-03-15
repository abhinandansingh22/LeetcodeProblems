class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix_sum(nums.size()), prefix_sum(nums.size()), ans(nums.size());
        int counter =1;
        prefix_sum[0] = 1;
        suffix_sum[nums.size()-1] =1;
        for(int i=1; i<nums.size(); i++){
            prefix_sum[i] = nums[i-1] * prefix_sum[i-1];

        }
        for(int j=nums.size()-2; j>=0; j--){
            suffix_sum[j] = nums[j+1] * suffix_sum[j+1];
        }
        for(int l = 0; l<nums.size(); l++){
            ans[l] = prefix_sum[l] * suffix_sum[l];
        }

        

        return ans;


        
    }
};