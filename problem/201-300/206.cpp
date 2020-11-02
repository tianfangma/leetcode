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

    ListNode* reverseList(ListNode* head) {
        stack<int> stk;
        ListNode* lNode=head;
        while(lNode!=nullptr)
        {
            stk.emplace(lNode->val);
            lNode=lNode->next;
        }
        lNode=head;
        while(lNode!=nullptr)
        {
            lNode->val=stk.top();
            stk.pop();
            lNode=lNode->next;
        }
        return head;
    }
};

//iteration edition by pointer
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*prev=nullptr;
        ListNode*curr=head;
        while(curr!=nullptr)
        {
            ListNode *nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
};

//recursive edition
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode* p=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return p;
    }
};

