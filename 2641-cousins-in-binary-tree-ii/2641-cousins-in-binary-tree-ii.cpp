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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return nullptr;

        queue<TreeNode*>q;
        int prev =root->val;
        q.push(root);
        

        while(!q.empty()){

            int n = q.size();
             int currsum = 0;

            while(n--){

            int sibsum = 0;
            TreeNode* node = q.front(); q.pop();
            node->val = prev-node->val;

            if(node->left){
                sibsum+=node->left->val;
            }
            if(node->right){
                sibsum+=node->right->val;
            }

            if(node->left){
              currsum+=node->left->val;
              node->left->val = sibsum;
              q.push(node->left);
            }

            if(node->right){
              currsum+=node->right->val;
              node->right->val = sibsum;
              q.push(node->right);
            }
            
            }

            prev = currsum;
        }

     return root;
    }
};