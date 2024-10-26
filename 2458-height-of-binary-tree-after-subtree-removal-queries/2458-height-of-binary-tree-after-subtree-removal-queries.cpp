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
    int solveRec(int level,TreeNode*root,unordered_map<int,int>&lvl,
        unordered_map<int,pair<int,int>>&lvlHeights,
        unordered_map<int,int>&lvlCont){
        if(root==NULL) return 0;

        int left=solveRec(level+1,root->left,lvl,lvlHeights,lvlCont);
        int right=solveRec(level+1,root->right,lvl,lvlHeights,lvlCont);

        int curHeight=max(left,right)+1;
        lvl[root->val]=level;
            
            if(lvlHeights.find(level)==lvlHeights.end()){
                lvlHeights[level]={curHeight,0};
                lvlCont[level]=root->val;
            }
            else if(curHeight>lvlHeights[level].first){
                lvlHeights[level].second=lvlHeights[level].first;
                lvlHeights[level].first=curHeight;
                lvlCont[level]=root->val;
            }
            else if(lvlHeights[level].second<= curHeight && 
                curHeight<=lvlHeights[level].first){
                lvlHeights[level].second=curHeight;
            }
        return curHeight;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int,int>lvl;
        unordered_map<int,pair<int,int>>lvlHeights;
        unordered_map<int,int>lvlCont;
        solveRec(0,root,lvl,lvlHeights,lvlCont);
        
        vector<int>ans;
        for(auto q:queries){
            int curAns=lvl[q]-1;
            if(lvlCont[lvl[q]]==q) curAns+=lvlHeights[lvl[q]].second;
            else curAns+=lvlHeights[lvl[q]].first;
            ans.push_back(curAns);
        }
        return ans;
    }
};