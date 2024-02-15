class Solution {
public:
    long long largestPerimeter(vector<int>& n) {
    long long sum = accumulate(begin(n), end(n), 0LL);
    for (auto pq = priority_queue<int>(begin(n), end(n)); pq.size() > 2; pq.pop()) {
        if (pq.top() < sum - pq.top())
            return sum;
        sum -= pq.top();
    }
    return -1;
}
};