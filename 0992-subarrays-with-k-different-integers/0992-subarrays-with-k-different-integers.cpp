class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0, ii = -1; 
        unordered_map<int, int> freq; 
        queue<int> q; 
        
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++; 
            q.push(i); 
            if (freq.size() > k) {
                ii = q.front(); q.pop(); 
                freq.erase(nums[ii]); 
            }
            
            while (freq[nums[q.front()]] > 1) {
                int k = q.front(); q.pop(); 
                freq[nums[k]]--; 
            }
            
            if (freq.size() == k) ans += q.front() - ii; 
        }
        return ans; 
    }
};