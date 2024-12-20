/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse_inorder(TreeNode* &node, int level, unordered_map<int, vector<TreeNode*>>& odd_level_to_nodes_map) {
        if (node == nullptr)    return;

        traverse_inorder(node->left, level+1, odd_level_to_nodes_map);
        if (level % 2 == 1)     odd_level_to_nodes_map[level].push_back(node);
        traverse_inorder(node->right, level+1, odd_level_to_nodes_map);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        unordered_map<int, vector<TreeNode*>> odd_level_to_nodes_map;
        traverse_inorder(root, 0, odd_level_to_nodes_map);

        for (const auto& [level, tree_nodes] : odd_level_to_nodes_map) {
            const int n = tree_nodes.size(); 
            for (int i=0; i<n/2; ++i)     std::swap(tree_nodes[i]->val, tree_nodes[n-1-i]->val);
        }

        return root;
    }
};