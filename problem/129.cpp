/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //dfs
class Solution {
public:
    int dfs(TreeNode* node,int preSum)
    {
        if(node==nullptr)
        {
            return 0;
        }
        int sum=preSum*10+node->val;
        if((node->left==nullptr)&&(node->right==nullptr))//访问到根结点
        {
            return sum;
        }
        else
        {
            return dfs(node->left,sum)+dfs(node->right,sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};

//bfs
//同时维护两个队列
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        int sum=0;
        queue<TreeNode*>nodeQueue;
        queue<int>numQueue;
        nodeQueue.push(root);
        numQueue.push(root->val);
        while(!nodeQueue.empty())
        {
            TreeNode* node=nodeQueue.front();
            int num=numQueue.front();
            nodeQueue.pop();
            numQueue.pop();
            TreeNode*left=node->left;
            TreeNode*right=node->right;
            if(left==nullptr&&right==nullptr)
            {
                sum+=num;
            }
            else
            {
                if(left!=nullptr)
                {
                    nodeQueue.push(left);
                    numQueue.push(num*10+left->val);
                }
                if(right!=nullptr)
                {
                    nodeQueue.push(right);
                    numQueue.push(num*10+right->val);
                }
            }
        }
        return sum;
    }
};
