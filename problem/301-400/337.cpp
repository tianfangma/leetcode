/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //f表示选中当前节点，g表示未选中当前节点

//dfs
class Solution {
public:
    unordered_map<TreeNode*,int>f,g;
    void dfs(TreeNode* node)
    {
        if(node==nullptr)
        {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        f[node]=node->val+g[node->left]+g[node->right];
        g[node]=max(f[node->left],g[node->left])+max(f[node->right],g[node->right]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root],g[root]);
    }
};

//
