class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        priority_queue<pair<char, int>> pq; 

        unordered_map<char, int> m;

        for(int i=0; i<s.size(); i++)
        {
            m[s[i]]++;
        }   

        for(auto it : m)
        {
            pq.push({it.first, it.second});
        }

        string ans = "";

        while(pq.size() > 1)
        {
            auto top1 = pq.top();
            pq.pop();

            auto top2 = pq.top();
            pq.pop();

            if(top1.second <= repeatLimit)
            {
                for(int i=0; i<top1.second; i++)
                {
                    ans += top1.first;
                }

                pq.push(top2);
            }
            else
            {
                for(int i=0; i<repeatLimit; i++)
                {
                    ans += top1.first;
                    top1.second--;
                }
                pq.push(top1);

                ans+= top2.first;
                top2.second--;
                if(top2.second > 0)
                {
                    pq.push(top2);
                }
            }
        }

        if(pq.size() > 0)
        {
            auto top1 = pq.top();
            pq.pop();

            if(top1.second > repeatLimit)
            {
                for(int i=0; i<repeatLimit; i++)
                {
                    ans += top1.first;
                    top1.second--;
                }
            }
            else
            {
                for(int i=0; i<top1.second; i++)
                {
                    ans += top1.first;
                }
            }
        }

        return ans;
    }
};