/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    StringBuilder stb = new StringBuilder();

    public String getDirections(TreeNode root, int startValue, int destValue) {
        if (root == null) {
            return "";
        }

        TreeNode LCAnode = LCA(root, startValue, destValue);


        pathfinder(LCAnode, stb, startValue);
        String left = stb.toString();
        stb.setLength(0);
        pathfinder(LCAnode, stb, destValue);
        String right = stb.toString();

        for (int i = 0; i < left.length(); i++) {
            right = 'U' + right;
        }

        return right;

    }

    public boolean pathfinder(TreeNode LCA, StringBuilder stb, int value) {

       //if node is null return null
        if (LCA == null) {

            return false;
        }
     //the moment you got u r node return true
        if (LCA.val == value) {
            return true;
        }

        stb.append('L');

        if (pathfinder(LCA.left, stb, value)) {
            return true;
        }

        stb.deleteCharAt(stb.length() - 1);

        stb.append('R');

        if (pathfinder(LCA.right, stb, value)) {
            return true;
        }
        stb.deleteCharAt(stb.length() - 1);
        return false;
    }
//This Method is Used to Find LCA node;
    public TreeNode LCA(TreeNode root, int p, int q) {
        if (root == null) {
            return null;

        }

        if (root.val == p || root.val == q) {
            return root;
        }

        TreeNode left = LCA(root.left, p, q);
        TreeNode right = LCA(root.right, p, q);

        if (left == null) {
            return right;
        } else if (right == null) {
            return left;
        } else {
            return root;
        }
    }
}