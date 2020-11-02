/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //iteration edition by stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        bool res=true;
        stack<int> stk;
        ListNode*lNode=head;
        while(lNode!=nullptr)
        {
            stk.emplace(lNode->val);
            lNode=lNode->next;
        }
        lNode=head;
        while(lNode!=nullptr)
        {
            if(lNode->val!=stk.top())
            {
                res=false;
                break;
            }
            stk.pop();
            lNode=lNode->next;
        }
        return res;
    }
};
