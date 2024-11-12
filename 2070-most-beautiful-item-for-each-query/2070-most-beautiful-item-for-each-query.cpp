class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort the items by price in ascending order
        sort(items.begin(), items.end());

        // Create a vector of pairs (query, index)
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ret(queries.size());
        int maxBeauty = 0;
        int i = 0;

        // Iterate through the sorted queries
        for (const auto& [query, index] : sortedQueries) {
            // Find the rightmost item with price <= query
            while (i < items.size() && items[i][0] <= query) {
                maxBeauty = max(maxBeauty, items[i][1]);
                i++;
            }
            ret[index] = maxBeauty;
        }

        return ret;
    }
};