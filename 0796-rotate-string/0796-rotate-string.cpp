class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        int n=s.length();
        for(int i=0; i<n; i++)
        {
            s.push_back(s[i]);
            if(s.substr(i+1)==goal)
                return true;
        }
        return false;
    }
};