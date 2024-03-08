class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      map<int,int>mp;
      int maxi=INT_MIN;
      for(auto i:nums)
      {
          mp[i]++;
          maxi=max(maxi,mp[i]);
      }  
        int c=0;
      for(auto i:mp)
      {
          if(i.second==maxi)
          {
              c+=i.second;
          }
      }
    
  return c;
    }
};