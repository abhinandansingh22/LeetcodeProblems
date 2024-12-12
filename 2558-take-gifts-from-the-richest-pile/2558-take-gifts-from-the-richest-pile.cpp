class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
    
    // Create a max-heap using a priority queue
    priority_queue<int> maxHeap(gifts.begin(), gifts.end());

    // Perform k operations
    for (int i = 0; i < k; ++i) {
        int maxGifts = maxHeap.top();
        maxHeap.pop();
        int remainingGifts = floor(sqrt(maxGifts));
        maxHeap.push(remainingGifts);
    }

    // Sum up the remaining gifts
    long long totalGifts = 0;
    while (!maxHeap.empty()) {
        totalGifts += maxHeap.top();
        maxHeap.pop();
    }

    return totalGifts;
}
};