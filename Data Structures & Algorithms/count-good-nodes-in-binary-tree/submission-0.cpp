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
    int countG(TreeNode* root, int maxv){
        if(!root){
            return 0;
        }
        int l = 0;
        int r = 0;
        int f = 0;
        if(root -> val >= maxv){
            f = 1;
        }
        maxv = std::max(maxv, root -> val);
        if(root -> left){
            l = countG(root -> left, maxv);
        }
        if(root -> right){
            r = countG(root -> right, maxv);
        }
        return l + r + f;
    }

    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int count = countG(root, root -> val);
        return count;
    }
};
