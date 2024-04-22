class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        queue<pair<string, int>> q;
        unordered_set<string> deadend;
        unordered_set<string> visited;
        string start = "0000";
        int move[2] = {-1, 1};
        
        if(start == target) return 0;

        for(string s: deadends)
            deadend.insert(s);
        
        if(deadend.find(start) == deadend.end()) {
            q.push({start, 0});
            visited.insert(start);
        }

        while(!q.empty()) {

            auto p = q.front();
            q.pop();
            string pos = p.first;
            int d = p.second;

            for(int i = 0; i <= 4; i++) {
                for(int j = 0; j < 2; j++) {

                    string newPos = pos;
                    newPos[i] = '0' + (newPos[i] - '0' + move[j] + 10) % 10;

                    if(newPos == target) return d + 1;
                    if(deadend.find(newPos) == deadend.end() && 
                        visited.find(newPos) == visited.end()) {
                        q.push({newPos, d + 1});
                        visited.insert(newPos);
                    }
                }
            }
        }
        
        return -1;
    }
};