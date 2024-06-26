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
    void inorder(TreeNode *root,vector<int>&nums)
    {
        if(root==NULL) return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    TreeNode* build(vector<int>&nums,int start,int end)
    {
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=build(nums,start,mid-1);
        root->right=build(nums,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>nums;
        inorder(root,nums);
        // for(int i=0;i<nums.size();i++)cout<<nums[i]
        return build(nums,0,nums.size()-1);
    }
};