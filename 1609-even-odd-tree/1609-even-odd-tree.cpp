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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return false;
        if(!(root->val%2)) return false;
        queue<TreeNode*>Q;
        int l = 0;
        Q.push(root);
        Q.push(NULL);
        bool newLevel = true;
        int prev = root->val;
        while(!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            if(node == NULL)
            {
                if(Q.empty())
                    continue;
                Q.push(NULL);
                l++;
                newLevel = true;
                continue;
            }
            if(
                    ((l % 2) && ((node->val%2) || !newLevel && node->val >= prev)) || 
                    (!(l % 2) && (!(node->val%2) || !newLevel && node->val <= prev))
                )
                return false;
            if(node->left)
                Q.push(node->left);
            if(node->right)
                Q.push(node->right);
            prev = node->val;
            newLevel = false;
        }
        return true;
    }
};