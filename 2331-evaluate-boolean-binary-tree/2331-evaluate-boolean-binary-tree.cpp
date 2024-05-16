class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
           return (bool)root->val;
        }
        if(root->val == 2){
            bool leftVal = evaluateTree(root->left);
            if(leftVal == true)return true;
            return evaluateTree(root->right);
        }else{
            bool leftVal = evaluateTree(root->left);
            if(leftVal == false)return false;
            return evaluateTree(root->right);
        }
    }
};