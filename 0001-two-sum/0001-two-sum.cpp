class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // [1] save original indices into an array of pairs
        vector<pair<int, int>> pairs(nums.size());
        for (int i = 0; i < nums.size(); ++i) pairs[i] = make_pair(nums[i], i);
        
        // [2] by sorting, we destroy the original indexing scheme
        //     (it is OK, we save original indices)
        sort(pairs.begin(), pairs.end());
        
        // [3] perform linear scan with two converging pointers
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int sum = pairs[left].first + pairs[right].first;
            if (sum == target)
                return {pairs[left].second, pairs[right].second};
            else if (sum > target)
                right -= 1;
            else
                left += 1;
        }
        
        // unreachable
        return {};
    }
};