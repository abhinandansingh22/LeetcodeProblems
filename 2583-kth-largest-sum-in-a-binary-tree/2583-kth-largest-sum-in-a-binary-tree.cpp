class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long ,vector<long long >,greater<long long>>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            long long val = 0;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                val += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            pq.push(val);
            while(pq.size() > k){
                pq.pop();
            }
        }
        return pq.size() < k ? -1 : pq.top();
    }
};