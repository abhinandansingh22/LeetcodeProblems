class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();
        priority_queue<pair<int,int>> maxheap;
        for (int i = 0; i < n; i++) {
            maxheap.push({score[i], i});
        }
        
        int times = 0;
        vector<string> result(n, "-1");   
        while (!maxheap.empty()) {
            int idx = maxheap.top().second;
            maxheap.pop();
            if (times == 0)          result[idx] = "Gold Medal";
            else if (times == 1)     result[idx] = "Silver Medal";
            else if (times == 2)     result[idx] = "Bronze Medal";
            else                     result[idx] = to_string(times + 1);
            times++;
        }
        return result;
    }
};
