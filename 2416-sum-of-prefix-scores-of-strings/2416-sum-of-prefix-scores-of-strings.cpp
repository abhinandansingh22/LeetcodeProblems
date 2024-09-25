class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int count; 

    TrieNode() : count(0) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->count++; 
        }
    }

    int calculateScore(const std::string& word) {
        TrieNode* node = root;
        int totalScore = 0;
        for (char ch : word) {
            if (node->children.count(ch)) {
                node = node->children[ch];
                totalScore += node->count; 
            } else {
                break;
            }
        }
        return totalScore;
    }
};

class Solution {
public:
    std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
        Trie trie;
        std::vector<int> result(words.size());

        for (const std::string& word : words) {
            trie.insert(word);
        }

        for (int i = 0; i < words.size(); ++i) {
            result[i] = trie.calculateScore(words[i]);
        }

        return result;
    }
};