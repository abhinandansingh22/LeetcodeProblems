class Solution {
public:
   int helper(string &s,int x,int y,char ch1,char ch2)
   {
       stack<char>st;
       int ans=0;
       for (int i=0;i<s.size();i++)
       {
           if (s[i]==ch2)
           {
               if(!st.empty() && st.top()==ch1)
               {
                   st.pop();
                   ans+=x;
               }
               else st.push(s[i]);
           }
           else{
               st.push(s[i]);
           }
       }
       s="";
       while(!st.empty())
       {
           s+=st.top();
           st.pop();
       }
       reverse(s.begin(),s.end());
       return ans;
   }
    int maximumGain(string s, int x, int y) {
        int c=0;
        if (x>y){ c=helper(s,x,y,'a','b');
                c+=helper(s,y,x,'b','a');}
        else {c=helper(s,y,x,'b','a');
               c+=helper(s,x,y,'a','b');}
               return c;
    }
};