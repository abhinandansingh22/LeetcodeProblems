class Solution 
{
public:
    bool parseBoolExpr(string expression) 
    {
        stack<char> st;
        int n=expression.size();
        for(int x=0; x<n; x++)
        {
            if(expression[x]==',') continue;
            if(expression[x]==')')
            {
                stack<char> t;
                while(!st.empty() && st.top()!='(')
                {
                    t.push(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                if(op=='&')
                {
                    char ans='t';
                    while(!t.empty())
                    {
                        if(t.top()=='f')
                        {
                            ans='f';
                            break;
                        }
                        t.pop();
                    }
                    st.push(ans);
                }
                else if(op=='|')
                {
                    char ans='f';
                    while(!t.empty())
                    {
                        if(t.top()=='t')
                        {
                            ans='t';
                            break;
                        }
                        t.pop();
                    }
                    st.push(ans);
                }
                else
                {
                    char ans='t';
                    if(t.top()=='t') ans='f';
                    st.push(ans);
                }
            }
            else
            {
                st.push(expression[x]);
            }
        }
        if(st.top()=='f') return false;
        return true;
    }
};