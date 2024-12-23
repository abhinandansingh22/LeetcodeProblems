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
  int cyclic_count(vector<int> &nums)
{
    map<int , int> mp ;
    int n= nums.size() ;

    int ans = 0 ;

    for(int i = 0 ; i < nums.size() ; i++)
        mp[nums[i]] = i ;
        
    sort(nums.begin(), nums.end());

    vector<bool> tmp(n, false);

    for (int i = 0; i < n; i++)
    {
        if (tmp[i] || mp[nums[i]] == i)
        {
            continue;
        }

        int j = i;
        int cnt = 0;
        while (!tmp[j])
        {
            cnt++;
            tmp[j] = true;
            j = mp[nums[j]];
        }

        if (cnt)
            ans = ans + (cnt - 1);
    }

    return (ans);
}


  int minimumOperations(TreeNode* root) {
       int cost = 0 ;

       queue<TreeNode *> q ;
       q.push(root) ;

       while(q.size() != 0)
          {       
              int size = q.size() ;
              vector<int> v ;

              for(int i = 0 ; i < size ; i++)
                {
                     TreeNode *node = q.front() ;
                     q.pop() ;
                     v.push_back(node->val);

                     if(node->left)
                       {
                          q.push(node->left);
                       }

                     if(node->right)
                       {
                         q.push(node->right);
                       }
                } 

                cost = cost + cyclic_count(v);
          }

         return cost ;
    }
};