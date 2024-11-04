class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        vector<pair<char, int>> count;
        int currCount = 1;
        char currChar = word[0];
        for (int i = 0; i < n; i++) {
            if (currCount == 9 or word[i + 1] != word[i]) {
                pair<char, int> p = {currChar, currCount};
                count.push_back(p);
                currChar = word[i + 1];
                currCount = 1;
            } else {
                currCount += 1;
            }
        }
        string cmp = "";
        for (auto it : count) {
            cmp.push_back(it.second + '0');
            cmp.push_back(it.first);
        }

        return cmp;
    }
};