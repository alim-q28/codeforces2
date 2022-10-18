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
public:
    bool check(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr or root2==nullptr){
            return root1==root2;
        }
        return root1->val==root2->val and check(root1->left,root2->right) and check(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};
