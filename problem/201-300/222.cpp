/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//by tianfangma
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left+right+1;
    }
};
