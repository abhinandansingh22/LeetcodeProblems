class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<int>>adj[n];

        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }

        queue<vector<int>>pq;
        vector<int>dis(n+1,INT_MAX);
        int ans=INT_MAX;
        
        pq.push({0,src,0});
        dis[src]=0;
        
        while(!pq.empty()){
            int currNode=pq.front()[1];
            int currDist=pq.front()[0];
            int stops=pq.front()[2];
            pq.pop();
            
            for(auto it:adj[currNode]){
                if(it[0]==dst && stops<=k)
                    ans=min(ans,currDist+it[1]);
                if(dis[it[0]]>currDist+it[1]){
                    dis[it[0]]=currDist+it[1];
                    pq.push({dis[it[0]],it[0],stops+1});
                }
                 if(it[0]==dst && stops<=k)
                    ans=min(ans,dis[it[0]]);
            }
            
        }
        if(ans == INT_MAX)
        return -1;
        return ans;
    }
};