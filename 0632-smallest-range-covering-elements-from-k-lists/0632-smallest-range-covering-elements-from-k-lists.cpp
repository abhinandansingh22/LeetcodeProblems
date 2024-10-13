class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2,0);
        ans[1] = INT_MAX;
        int k = nums.size();
        vector<pair<int,int>> vec;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                vec.emplace_back(nums[i][j],i);
            }
        }
        sort(vec.begin(),vec.end());
        vector<int> temp(2,0);
        temp[1] = INT_MAX;
        unordered_map<int,int> mp;
        for (int r = 0, l = 0; r < vec.size(); r++) {
            auto [num,freq] = vec[r];
            mp[freq]++;
            if (mp.size() == k) temp[1] = num;
            while (l < vec.size() && mp.size() == k) {
                auto [numl,freql] = vec[l];
                temp[0] = numl;
                mp[freql]--;
                if (mp[freql] == 0) mp.erase(freql);
                l++;
            }
            if (temp[1]-temp[0] < ans[1]-ans[0]) {
                ans[1] = temp[1];
                ans[0] = temp[0];
            }
        }
        return ans;
    }
};