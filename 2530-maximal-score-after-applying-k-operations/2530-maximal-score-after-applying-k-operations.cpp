class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> pq;
        int n = nums.size();

        long long score = 0;

        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        for(int i=0; i<k; i++){
            int x = pq.top();
            pq.pop();
            score += x;
            pq.push((x+2)/3);
        }

        return score;
    }
};