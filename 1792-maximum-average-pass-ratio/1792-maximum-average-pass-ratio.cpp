class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<float,pair<int,int>>>pq;
        for(auto v : classes){
            float p = ((float)(v[0]+1))/((float)(v[1]+1)) - ((float)v[0])/((float)v[1]);
            pair<int,int> a;
            a.first = v[0];
            a.second = v[1];
            pair <float,pair<int,int>> b;
            b.first = p;
            b.second = a;
            pq.push(b);
        }
        for(int i=0;i<extraStudents;i++){
            pair <float, pair<int,int>> a = pq.top();
            a.second.first++;
            a.second.second++;
            int a1 = a.second.first, a2 = a.second.second;
            a.first = ((float)(a1+1))/((float)(a2+1)) - ((float)a1)/((float)a2);
            pq.pop();
            pq.push(a);
        }
        double ans = 0.0,sum=0.0;
        while(!pq.empty()){
            sum+=(double)pq.top().second.first/(double)pq.top().second.second;
            pq.pop();
        }
        ans = sum/(double)classes.size();
        return ans;
    }
};