class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& og, int m, int n) {
        int count=0;
        vector<int>v;
        if(og.size()!=m*n){
            return {};
        }
        vector<vector<int>>ans;
        for(int i=0;i<og.size();i++){
            v.push_back(og[i]);
            count++;
            if(count==n){
                ans.push_back(v);
                count=0;
                v.clear();
            }
        }
        return ans;
    }
};