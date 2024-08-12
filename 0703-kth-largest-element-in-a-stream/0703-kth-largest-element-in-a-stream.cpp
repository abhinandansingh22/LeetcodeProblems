class KthLargest {
public:
    int x;
    vector<int>v;
    KthLargest(int k, vector<int>& nums) {
        x=k;
        for(int i=0;i<nums.size();i++) {
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
    }
    
    int add(int val) {
        int index = lower_bound(v.begin(), v.end(), val)-v.begin();
        v.insert(v.begin()+index,val);  
        return v[v.size()-x];
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */