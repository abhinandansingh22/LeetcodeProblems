class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int maxk=-1,mink=-1,nok=-1;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                nok=i;
            }
            if(nums[i]==minK)
                mink=i;
            if(nums[i]==maxK)
                maxk=i;
            ans+=max(0,min(mink,maxk)-nok);
        }
        return ans;
    }
};