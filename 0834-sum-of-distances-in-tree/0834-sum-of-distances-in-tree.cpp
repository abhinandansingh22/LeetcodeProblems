class Solution {
public:
    vector<int>indp,outdp,sz;
    int n;
    vector<vector<int>> adj;
    void dfs1(int node,int par){

        indp[node] = 0;
        sz[node]=1;

        for(auto ch : adj[node]){

            if(ch == par ) continue;
            dfs1(ch,node);
            sz[node] += sz[ch];
            indp[node] +=(indp[ch]+sz[ch]);
        }

    }

    void dfs2(int node,int par){
        if(par==-1){
          outdp[node]=0;
        }
        else{
            outdp[node] = outdp[par]+n-sz[par] +(indp[par]-indp[node]-sz[node] + sz[par] -sz[node]);
        }
        for(auto ch : adj[node]){
            if(ch == par) continue;
            dfs2(ch,node);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n=N;
       adj.resize(n);

        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        indp.resize(n,0);
        sz.resize(n,0);
        outdp.resize(n,0);
        dfs1(0,-1);
        dfs2(0,-1);
        
        for(int i=0;i<n;i++){
            indp[i]+=outdp[i];
        }
        return indp;
    }
};