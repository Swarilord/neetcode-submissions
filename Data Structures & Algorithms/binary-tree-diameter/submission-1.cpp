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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return std::max(
            height(root -> left) + 1,
            height(root -> right) + 1
        );
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int dia = height(root -> left) + height(root -> right);
        int m1 = std::max(dia, diameterOfBinaryTree(root -> left));
        return std::max(m1, diameterOfBinaryTree(root -> right));
    }
};
