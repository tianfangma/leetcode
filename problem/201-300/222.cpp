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
    int count=0;
    void countNode(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        count++;
        countNode(root->left);
        countNode(root->right);
    }
    int countNodes(TreeNode* root) {
        countNode(root);
        return count;
    }
};
