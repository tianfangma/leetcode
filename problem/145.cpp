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
 
 //recrusive edition
class Solution {
public:
    vector<int> res;
    void postorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        res.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return res;
    }
};

//iteration edition
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
        {
            return res;
        }
        stack<TreeNode*> stk;
        TreeNode* node=root;
        TreeNode* prev=nullptr;
        while(!stk.empty()||node!=nullptr)
        {
            while(node!=nullptr)
            {
                stk.emplace(node);
                node=node->left;
            }
            node=stk.top();
            stk.pop();
            if(node->right==nullptr||node->right==prev)
            {
                res.emplace_back(node->val);
                prev=node;
                node=nullptr;
            }
            else
            {
                stk.emplace(node);
                node=node->right;
            }
        }
        return res;
    }
};
