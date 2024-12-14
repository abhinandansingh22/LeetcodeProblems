class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0], mini = nums[0];
        int i = 0, j = 0;
        long long int cnt = 0;
        map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            maxi = max(maxi,nums[j]);
            mini = min(mini,nums[j]);
            while(abs(maxi-mini)>2 && i<n && i<=j){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                    if(nums[i]==maxi){
                        auto it = mp.end();
                        it--;
                        maxi = it->first;
                    }
                    if(nums[i]==mini){
                        auto it = mp.begin();
                        mini = it->first;
                    }
                }
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};