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
 
 //by tianfangma
class Solution {
public:
    void solute(TreeNode*root,TreeNode*pre,int val,int flag)
    {
        if(root==nullptr)
        {
            if(flag)
            {
                pre->right=new TreeNode(val,nullptr,nullptr);
            }
            else
            {
                pre->left=new TreeNode(val,nullptr,nullptr);
            }
            return;
        }
        pre=root;
        if(root->val>val)
        {
            solute(root->left,pre,val,0);
        }
        else
        {
            solute(root->right,pre,val,1);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)
        {
            return new TreeNode(val,nullptr,nullptr);
        }
        if(root->val>val)
        {
            solute(root->left,root,val,0);
        }
        else
        {
            solute(root->right,root,val,1);
        }
        return root;
    }
};
