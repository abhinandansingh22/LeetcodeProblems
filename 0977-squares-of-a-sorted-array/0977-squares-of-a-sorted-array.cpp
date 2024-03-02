class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int start = 0;
        int end = nums.size() -1;
        int index = end;
        while(start <= end)
        {
            if(abs(nums[end]) < abs(nums[start]))
            {
                ans[index] = nums[start]*nums[start];
                start++;
                index--;
            }
            else
            {
                ans[index] = nums[end]* nums[end];
                end--;
                index--;
            }
            
        }
        return ans;
        
    }
};