class Solution {
public:

   void dfs(int node , int par , int de , vector <int> &d , vector <vector <int>> &g){
    d[node] = de ; 
    for(int i = 0; i < (int)g[node].size() ; i++){
        if(par != g[node][i]){
            dfs(g[node][i] , node , de+1 , d , g) ; 
        } 
    } 
   }



   int getd(vector <vector <int>> &g , int n){
       vector <int> d(n , 0) ;
       dfs(0 , -1 , 0 , d , g) ; 
       int maxi = -1e9 ; 
       int x = -1 ;
       for(int i = 0 ;i < n ; i++){
          if(d[i] > maxi){
             maxi = d[i] ; 
             x =i; 
          }
       } 
       d.clear() ;
       dfs(x , -1 , 0 , d , g) ;
       maxi = -1e9 ; 
       for(int i = 0 ;i < n ; i++){
         maxi = max(maxi , d[i]) ; 
       }
       return maxi ;  
   }




    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
       int n , m  ;

       n = (int)e1.size()+1 ; 
       m  = (int)e2.size() +1 ; 
      vector <vector <int>> g1 , g2 ; 
  
       g1.resize(n) ; 
       g2.resize(m) ; 

       for(int i = 0 ; i < n-1 ; i++){
        int u = e1[i][0] ; 
        int v = e1[i][1] ; 
        g1[u].push_back(v) ; 
        g1[v].push_back(u) ; 
       }
       
       for(int i = 0 ; i < m-1 ; i++){
        int u = e2[i][0] ; 
        int v = e2[i][1] ; 
        g2[u].push_back(v) ; 
        g2[v].push_back(u) ; 
       }
       int d1 = getd(g1 , n) ; 
       int d2 = getd(g2 , m) ; 

       if(d1%2 == 0 && d2%2 == 0){
        return (max ({(d1/2) + (d2/2) + 1 , d1 , d2 })) ;  
       }  
       if((d1%2 == 0 && d2%2 == 1) ){
          return max({d1/2 + ((d2+1)/2) + 1 , d1, d2}) ; 
       }
       if((d1%2 == 1 && d2%2 == 0) ){
        return max({d1 , d2 , d2/2 + ((d1+1)/2) + 1}) ; 
       }
       else{
        return max({d1 , d2 , ( ((d1+1)/2) + ((d2 +1 )/2) + 1) }) ; 
       }

    }
};