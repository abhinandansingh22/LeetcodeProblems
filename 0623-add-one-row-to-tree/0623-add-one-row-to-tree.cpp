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
TreeNode*solve(TreeNode*root,int val,int depth)
{
    if(root==NULL)
    return NULL;
    if(depth==2)
    {
        TreeNode* leftnode=new TreeNode(val);
        TreeNode* rightnode=new TreeNode(val);
        if(leftnode)
        leftnode->left=root->left;
        if(rightnode)
        rightnode->right=root->right;
        root->left=leftnode;
        root->right=rightnode;
        return root;
    }
    root->left=solve(root->left,val,depth-1);
    root->right=solve(root->right,val,depth-1);
    return root;
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode*newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        return solve(root,val,depth);
    }
};