class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v;
        vector<int> v2;
        unordered_map<int,int> umap;
        for(int i=0;i<arr1.size();i++){
            umap[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            while(umap[arr2[i]]>0){
                v.push_back(arr2[i]);
                umap[arr2[i]]--;
            }
        }
        for(auto x: umap){
            while(x.second>0){
                v2.push_back(x.first);
                x.second--;
            }
        }
        sort(v2.begin(), v2.end());

    v.insert(v.end(), v2.begin(), v2.end());
            
        return v;
    }
};