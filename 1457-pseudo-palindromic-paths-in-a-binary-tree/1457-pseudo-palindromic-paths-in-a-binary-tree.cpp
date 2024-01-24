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

    int ans=0;
    unordered_map<int,int> mp;
    void fun(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            int flag=0;
            int cnt=0;
            mp[root->val]++;
            for(auto it:mp){
                if(it.second%2==1){
                    cnt++;
                }
            }
            if(cnt<=1){
                ans++;
            }
            mp[root->val]--;
            return;
            // return 0;
        }
        mp[root->val]++;
        fun(root->left);
        fun(root->right);
        mp[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        fun(root);
        return ans;
    }
};