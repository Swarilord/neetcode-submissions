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
    void traverse(std::vector<int>& pre, TreeNode* root){
        if(!root){
            return;
        }
        traverse(pre, root -> left);
        pre.push_back(root -> val);
        traverse(pre, root -> right);
    }
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> pre; 
        traverse(pre, root);
        return pre.at(k - 1);
    }
};
