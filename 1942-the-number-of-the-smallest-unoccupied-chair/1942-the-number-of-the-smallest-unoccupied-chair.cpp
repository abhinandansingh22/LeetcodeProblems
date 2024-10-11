class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        priority_queue < int, vector<int>, greater<int> >pq1;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq2;
        
        vector<pair<int, int>>vec;
        for(int i=0; i<times.size(); i++)
        vec.push_back({times[i][0], i});

        sort(vec.begin(), vec.end());

        for(int i=0; i<vec.size(); i++)
        pq1.push(i);
        
        for(int i=0; i<vec.size(); i++)
        {
            int a = vec[i].first;
            int f = vec[i].second;

            while(!pq2.empty() && pq2.top().first <= a)
            {
                pq1.push(pq2.top().second);
                pq2.pop();
            }

            if(f == targetFriend)
            return pq1.top();
            
            pq2.push({times[f][1], pq1.top()});
          
            pq1.pop();
        }

        return -1;
    }
};