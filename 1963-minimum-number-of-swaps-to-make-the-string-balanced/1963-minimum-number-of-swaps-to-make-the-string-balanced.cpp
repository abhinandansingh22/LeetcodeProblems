class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(char &ch : s){
            if(ch == '['){
                st.push(ch);
            } else if(!st.empty()){
                st.pop();   // balancing opening & closing brackets
            }
        }

        return (st.size() + 1) / 2;   // i.e. (no of open brackets + 1) / 2
    }
};