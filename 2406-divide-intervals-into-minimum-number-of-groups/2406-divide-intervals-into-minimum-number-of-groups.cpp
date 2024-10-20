class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int res = 0, temp = 0, n = intervals.size();

        map<int, int> count;
        for (auto& i : intervals) {
            count[i[0]]++;
            count[i[1] + 1]--;
        }

        for (auto& c : count) {
            temp += c.second;
            res = max(res, temp);
        }
        return res;
    }
};