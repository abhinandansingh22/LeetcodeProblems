class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (auto it = prices.begin(); it != prices.end(); ++it) {
            auto minVl = find_if(next(it, 1), prices.end(),
                                 [&it](int a) { return a <= *it; });
            if (minVl != prices.end())
                *it -= *minVl;
        }
        return prices;
    }
};