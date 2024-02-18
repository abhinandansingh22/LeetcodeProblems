class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long,long long >,vector<pair<long long,long long >>,greater<pair<long long,long long >>>p;
        sort(meetings.begin(),meetings.end());
        vector<long long >vis(n,0);
        vector<long long >countt(n,0);
        for(auto k:meetings){
            int flg=1;
            while(p.size()>0&&p.top().first<=k[0]){
                auto m = p.top();
                p.pop();
                vis[m.second]=0;
                
            }
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    vis[i]=1;
                   
                    p.push({k[1],i});
                    countt[i]++;
                    flg=0;
                    break;
                }
            }
            if(flg==0)
                continue;
         
                auto m = p.top();
                p.pop();
                p.push({k[1]+m.first-k[0],m.second});
                countt[m.second]++;
                vis[m.second]=1;
            
        }
        long long  maxi = 0;
        long long  ans=0;
        for(int i=0;i<n;i++){
           if(maxi<countt[i]){
               ans=i;
               maxi = countt[i];
           }
        }
        return ans;
    }
};