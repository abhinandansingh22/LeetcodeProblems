class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xr=0;
        for(int i=0;i<nums.size();i++){
            xr^=nums[i];                //Taking XOR of all Elements
        }
        unsigned int kth=log2(xr&-xr); //finding rightmost set bit position use unsigned to avoid runtime error
        int xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&(1<<kth))){         //set 1 having kth bit set in element nums[i]
                xor1^=nums[i] ;
            }
            else{                           //set 2 having kth bit not set in element nums[i]
                xor2^=nums[i] ;
            }
        }
        return {xor1,xor2};
    }
};