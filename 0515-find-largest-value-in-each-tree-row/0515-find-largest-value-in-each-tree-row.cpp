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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<sz;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                maxi=max(maxi,n->val);
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};