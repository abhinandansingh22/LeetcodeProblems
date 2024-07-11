class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                queue<char> q;
                while(st.top()!='(')
                {
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(q.size()>0)
                {
                    st.push(q.front());
                    q.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};