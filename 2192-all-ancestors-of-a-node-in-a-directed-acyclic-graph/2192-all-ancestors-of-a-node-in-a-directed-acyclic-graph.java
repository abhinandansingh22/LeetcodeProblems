class Solution {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> adj=new ArrayList<>();
        for(int i=0;i<=n;i++)
        {
            adj.add(new ArrayList<>());
        }

        for(int i=0;i<edges.length;i++)
        {
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        List<List<Integer>>ans=new ArrayList<>();
        
        for(int i=0;i<n;i++)
        {
            
          List<Integer>l= bfs(adj,i,n);
          Collections.sort(l);
          ans.add(new ArrayList(l));
            
        }
        return ans;
    }
    public List<Integer> bfs(List<List<Integer>>adj,int i ,int n)
    {
        List<Integer> li=new ArrayList<>();
        int vis[]=new int[n];

        int cnt=0;
        Queue<Integer>q=new LinkedList<>();
        q.add(i);
        while(!q.isEmpty())
        {
            int node=q.poll();
            if(cnt!=0)
            li.add(node);
            cnt++;
            for(int it:adj.get(node))
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    q.add(it);
                }
            }
        }
        return li;
         
    }
}