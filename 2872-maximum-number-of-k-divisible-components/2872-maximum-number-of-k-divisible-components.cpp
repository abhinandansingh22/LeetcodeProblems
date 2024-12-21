class Solution {
public:
    long long dfs(int start,unordered_map<int,vector<int>>&ourmap,unordered_map<int,bool>&visited,vector<long long>&subtreesum,vector<int>&values,unordered_map<int,int>&parent){
        
        visited[start]=true;
        vector<int> temp=ourmap[start];
        for(int i=0;i<temp.size();i++){
            if(visited[temp[i]]!=true){
                parent[temp[i]]=start;
                subtreesum[start]=subtreesum[start]+dfs(temp[i],ourmap,visited,subtreesum,values,parent);
            }
        }
        subtreesum[start]=subtreesum[start]+values[start];
        return subtreesum[start];
    }
    void helper(int start,unordered_map<int,vector<int>>&ourmap,unordered_map<int,bool>&visited,vector<long long>&subtreesum,int k,unordered_map<int,int>&parent,set<pair<int,int>>&s){
        
        visited[start]=true;
        vector<int> temp=ourmap[start];
        if(subtreesum[start]%k==0 && parent[start]!=-1){
            s.insert({parent[start],start});
        }
        for(int i=0;i<temp.size();i++){
            if(visited[temp[i]]!=true){
                helper(temp[i],ourmap,visited,subtreesum,k,parent,s);
            }
        }  
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        unordered_map<int,vector<int>> ourmap;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            ourmap[a].push_back(b);
            ourmap[b].push_back(a);
        }
        unordered_map<int,bool> visited(false);
        vector<long long> subtreesum(n,0);
        unordered_map<int,int> parent;
        parent[0]=-1;
        dfs(0,ourmap,visited,subtreesum,values,parent);
        visited.clear();
        set<pair<int,int>> s;
        helper(0,ourmap,visited,subtreesum,k,parent,s);
        return s.size()+1;   
    }
};