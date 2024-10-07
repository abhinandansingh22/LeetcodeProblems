class Solution {
public:
    int minLength(string s) {
       stack<char> stk;

       for(char &it : s){
          if(!stk.empty() && stk.top()=='A' && it=='B'){
            stk.pop();
          }else if(!stk.empty() && stk.top()=='C' && it=='D'){
            stk.pop();
          }else{
            stk.push(it);
          }
       }


        return stk.size();
    }
};