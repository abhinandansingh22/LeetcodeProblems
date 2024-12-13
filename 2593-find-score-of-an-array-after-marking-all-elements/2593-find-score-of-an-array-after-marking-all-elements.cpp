class Solution {
public:
    long long findScore(vector<int>& nums) {

        long long res = 0;

        // dont use a pq, instead we maintain a vector of pairs:
        vector<pair<int, int>> tmp;
        for (int i = 0; i < nums.size(); i += 1) {
            tmp.push_back({nums[i], i});
        }
        sort(tmp.begin(), tmp.end());
        vector<bool> marked(nums.size(), false);

        // iterate through this vector of pairs, and maintain a buffer if they are mrked or not.
        for (int i = 0; i < tmp.size(); i += 1) {
            int val = tmp[i].first, idx = tmp[i].second;
            if (marked[idx]) { continue; }
            
            // absorb into res:
            res += val;

            // mark the rest:
            marked[idx] = true;
            if (idx - 1 >= 0) { marked[idx - 1] = true; } 
            if (idx + 1 < nums.size()) { marked[idx + 1] = true; } 

        }
        return res;
    }
};