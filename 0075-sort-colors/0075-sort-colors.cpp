class Solution {
public:
    void sortColors(vector<int>& nums) {

    int count_0=0, count_1=0, count_2=0;
    int red=0;int white=1;int blue=2;
    int n=nums.size();

    for(int i=0;i<n;i++)
    {
        if(nums[i]==red)
        count_0++;
    }

    for(int i=0;i<n;i++)
    {
        if(nums[i]==white)
        count_1++;
    }

    for(int i=0;i<n;i++)
    {
        if(nums[i]==blue)
        count_2++;
    }

    for(int i=0; i<count_0 ;i++)
    nums[i]=red;

    for(int i=count_0; i<count_0 + count_1; i++)
    nums[i]=white;

    for(int i=count_0 + count_1; i<n; i++)
    nums[i]=blue;

    }
};