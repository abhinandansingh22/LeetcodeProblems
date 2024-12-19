class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int res = 0;
        while(i<n) {
            int maxi = nums[i];
            while(i<n && i!=maxi){
                i++;
                if(i<n) maxi = max(maxi, nums[i]);
            }
            i++;
            res += 1;
        }
        return res;
    }
};