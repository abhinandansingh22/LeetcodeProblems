class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        int ans=0;
        int bit=0;
        for(int i=0;i<arr.size();i++)
        {
            bit^=arr[i];
            for(int j=i+1;j<arr.size();j++)
            {
                bit^=arr[j];
                if(bit==0)
                    ans+=(j-i);
            }
            bit=0;
        }
        return ans;
    }
};