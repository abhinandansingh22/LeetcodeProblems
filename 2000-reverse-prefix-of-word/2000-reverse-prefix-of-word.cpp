class Solution {
public:
    string reversePrefix(string word, char ch) {
        string s;
        for(int i=0;i<word.size();i++){
            s.push_back(word[i]);
            if(word[i]==ch){
                reverse(s.begin(),s.end());
                break;
            }
        }
        for(int i=s.size();i<word.size();i++){
            s.push_back(word[i]);
        }
        return s;
    }
};