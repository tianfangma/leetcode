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
 
 //recurisive edition
class Solution {
public:
    vector<int> result;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return ;
        }
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
};

//iteration edition
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
        {
            return res;
        }
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(!stk.empty()||node!=nullptr)
        {
            while(node!=nullptr)
            {
                stk.emplace(node);
                node=node->left;
            }
            node=stk.top();
            stk.pop();
            res.emplace_back(node->val);
            node=node->right;
        }
        return res;
    }
};
