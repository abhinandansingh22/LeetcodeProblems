class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int >st;   // stack to store the index to each paranthesis
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                    st.pop();
                else
                    s[i]='@';
            }
        }
        while(!st.empty())   
        {
            int temp=st.top(); st.pop();
            s[temp]='@';    // updating the unbalanced paranthesis with '@'
        }
         s.erase(remove(s.begin(),s.end(),'@'),s.end()); // removing all occurence of '@'
        return s;
    }
};