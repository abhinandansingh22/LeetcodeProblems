class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, temp;
        vector<int> ans(queries.size(), -1);
        for(int i=0; i<queries.size(); i++){
            if(queries[i][0]== queries[i][1])   ans[i] = queries[i][0];
            else pq.push({max(queries[i][0], queries[i][1]), i});
        }
        
        for(int i=0; i<heights.size(); i++){
            while(!pq.empty() && pq.top().first==i){
                int query = pq.top().second;
                if(max(heights[queries[query][0]], heights[queries[query][1]]) == heights[i] && min(heights[queries[query][0]], heights[queries[query][1]]) != heights[i])   
                    ans[query] = i;
                else temp.push({ max(heights[queries[query][0]], heights[queries[query][1]]),query});
                pq.pop();
            }
            while(!temp.empty() && temp.top().first<heights[i]){
                ans[temp.top().second] = i;
                temp.pop();
            }
        }
        return ans;
    }
};