class Solution {
public:

    int countMaxOrSubsets(vector<int>& nums) {
        if (nums.empty()) return 0;
        int bitwise = 0;
        for (auto& n : nums) bitwise |= n;
        int res = 0;
        dfs(nums, 0, 0, bitwise, res);
        return res;
    }

    void dfs(vector<int>& nums, int idx, int path, int bitwise, int& res) {
        if (idx == nums.size()) return;

        int temp = path | nums[idx];
        if (temp == bitwise) res++;
        dfs(nums, idx + 1, temp, bitwise, res);
        dfs(nums, idx + 1, path, bitwise, res);
    }
};