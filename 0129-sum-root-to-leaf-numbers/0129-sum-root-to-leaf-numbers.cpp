class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        calculate(root,sum);
        return ans;
    }
private:
    int ans=0;
    void calculate(TreeNode* root,int sum){
        if(!root)
            return;
        sum = 10* sum+root->val;
        cout << sum <<endl;
        if(!root->left && !root->right)
            ans +=sum;
        calculate(root->left,sum);
        calculate(root->right,sum);
    }
};