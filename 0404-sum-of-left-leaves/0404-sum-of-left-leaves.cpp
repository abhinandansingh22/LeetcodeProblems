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
private:
    
    void findSum(TreeNode* root, int& sum, bool flag) {
        if (!root) return;
		// If we just went left, and there is a node, and it has no kids,
		// then we must be on a left leaf. Add its value to sum,
		// which persists amongst recursive calls as it is taken by reference
        if (flag && root && !root->left && !root->right ) {
            sum += root->val;
            return;
        }
		// Going left is always true
        findSum(root->left, sum, true);
		// Going right is always false
        findSum(root->right, sum, false);
        return;
    }
    
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        findSum(root, sum, false);
        return sum;
    }
};