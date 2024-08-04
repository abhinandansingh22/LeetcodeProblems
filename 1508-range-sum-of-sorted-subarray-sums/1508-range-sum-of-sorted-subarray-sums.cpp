class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>res;
        for(int i=0; i<n; i++){
            int ans=0;
            for(int j=0; j+i<n; j++){
                ans+=nums[j+i];
                res.push_back(ans);
            }
        }
        sort(res.begin(), res.end());
        long int ans=0;
        for(int i=left-1; i<right; i++){
            ans+=res[i];
        }
        return ans % (1000000007);
    }
};