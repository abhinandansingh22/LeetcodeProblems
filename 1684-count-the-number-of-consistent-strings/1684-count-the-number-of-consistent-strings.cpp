class Solution {
public:
   int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
    // Create a set of allowed characters for fast lookup
    int ans = 0;
    unordered_set<char> st(allowed.begin(),allowed.end());
    for(string s : words){
        bool consistant = true;
        for(char c : s){
            if(st.find(c) == st.end()){
                consistant = false;
                break;
            }
        }
        if(consistant){
            ++ans;
        }
    }
    return ans;
}
};