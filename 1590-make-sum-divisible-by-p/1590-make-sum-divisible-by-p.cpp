class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    int ans = INT_MAX, rem = accumulate(nums.begin(),nums.end(), 0L) % p, r = 0;
  
    if(rem == 0) return 0;
  
    unordered_map<int, int>table = {{0,-1}};
    for(int i = 0; i != nums.size(); table[r] = i++){
      int x = ( (r = (r + nums[i]) % p) >= rem ? r - rem : p - rem + r); 
      if(table.count(x)) ans = min<int>(ans, i - table[x]);
    }
    
    return ans == nums.size() ? -1 : ans;
  }
};