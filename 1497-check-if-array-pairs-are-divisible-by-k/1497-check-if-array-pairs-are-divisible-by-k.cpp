class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        std::ios::sync_with_stdio(false);
        int temp = 2;
        vector<int>mp(k,0);
        for(int i=0;i<arr.size();i++){
            int rem = ((arr[i]%k)+k)%k;//map of remainders
            mp[rem]++;
        }
        if(mp[0] %2 !=0) return 0;//for array[15,30,10,20] all divisible by k
        for(int i=1;i<=k/2;i++){
            int half = k-i;//if 1%5 =1 and half is 9%5 = 4 
            if(mp[half] != mp[i]){
                return 0;
            }
        }
        return 1;
    }
};