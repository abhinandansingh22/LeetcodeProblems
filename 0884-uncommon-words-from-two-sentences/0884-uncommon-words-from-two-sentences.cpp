class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        vector<string> ans;

        int i=0;
        while(i<s1.size()){
            string word = "";
            while(i<s1.size() && s1[i] != ' '){
                word.push_back(s1[i]);
                i++;
            }
            i++;
            mp[word]++;
        }


        i=0;
        while(i<s2.size()){
            string word = "";
            while(i<s2.size() && s2[i] != ' '){
                word.push_back(s2[i]);
                i++;
            }
            i++;
            mp[word]++;
        }

        

        for(auto it = mp.begin(); it != mp.end(); it++){
            pair<string,int> p = *it;
            if(p.second == 1)
            ans.push_back(p.first);
        }

        return ans;

    }
};