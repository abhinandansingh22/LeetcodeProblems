class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n =  nums.size(),i;
        sort(nums.rbegin(),nums.rend());
        for(i=0;i<nums.size();i++)
        {
            if(nums[nums.size()-1]<1)
            {
                nums.pop_back();
            }
    }
    sort(nums.begin(),nums.end());
    for(i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<nums.size();
    int max=*max_element(nums.begin(),nums.end());
if(nums.size()==max)
    {   int index=1;
    i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(index!=max)
            {
                if(nums[i]==index)
                {
                    if(nums[j]==nums[i])
                    {
                        i++;
                        j++;
                    }
                    index++;
                    i++;
                }
                else 
                return index;
            }
        }
        return max+1;
    }
    if(max<n)
    {
        max=n;
    }   

    //cout<<"\n"<<max;
    if(nums.size()==0)
    {
        return 1;
    }    
        for(i=1;i<=max;i++)
        {
            int c =count(nums.begin(),nums.end(),i);
            if(c<1)
            {
                return i;
                break;
            }
        }
        
        return 0;
    }
};