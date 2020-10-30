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
 
 //recursion edition
class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};

//iteration edition
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(root==nullptr)
        {
            return result;
        }
        stack<TreeNode*> s;
        TreeNode* node=root;
        while(node!=nullptr||!s.empty())
        {
            while(node!=nullptr)
            {
                result.emplace_back(node->val);
                s.emplace(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
            node=node->right;
        }
        return result;
    }
};
