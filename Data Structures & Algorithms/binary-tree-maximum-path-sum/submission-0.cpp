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

    int dfs(TreeNode* root, int& res){
        if(!root){
            return 0;
        }
        int leftMax = dfs(root -> left, res);
        int rightMax = dfs(root -> right, res);
        leftMax = std::max(leftMax, 0);
        rightMax = std::max(rightMax, 0);
        res = std::max(leftMax + rightMax + root -> val, res);
        return std::max(leftMax, rightMax) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        int res = root -> val;
        int v;
        v = dfs(root, res);
        return res;
    }
};
