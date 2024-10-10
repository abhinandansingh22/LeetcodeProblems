class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res=0,n=nums.size(); 
        
        map<int,int> mp; 
        mp[nums[0]]=0; 
        
        for(int i=1;i<n;i++){
            auto itr=mp.upper_bound(nums[i]); 
            if(itr!=mp.begin()) itr--;
            
            if(itr->first<=nums[i] )
            res=max(res,i-itr->second);
             
            if(nums[i]<mp.begin()->first)  mp[nums[i]]=i; 
        }
        return res;
    }
};