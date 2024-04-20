class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++){
            vector<int> arr;
            for(int j=l[i]; j<=r[i]; j++)
                arr.push_back(nums[j]);

            sort(arr.begin(), arr.end());
            int c=0;
            int diff = arr[1] - arr[0];
            for(int j=2; j<arr.size(); j++) {
                if(diff != (arr[j] - arr[j-1])) {
                    c++;
                }
            }
            if(c == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};