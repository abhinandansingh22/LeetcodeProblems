class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> s;
        if(n==1)
        return 1;
        for(int i = 0; i< trust.size(); i++)
        {
            for(int j = 0; j < trust[0].size(); j++)
            {
                s.insert(trust[i][j]);
            }
        }
        unordered_map<int, int> um;
        unordered_map<int, int> check;
        for(auto temo: s)
        {
            check[temo] = 0;
        }
        for(int i = 0; i< trust.size(); i++)
        {
            check[trust[i][0]]++;
            um[trust[i][1]]++;
        }
        for(auto itr: um)
        {
            if(itr.second == s.size()-1 && check[itr.first] <1)
            {
                return itr.first;
            }
        }
        return -1;
    }
};