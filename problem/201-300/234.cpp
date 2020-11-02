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

//fast and slow pointer
class Solution {
public:
    //快慢指针，当快指针走到链表尾，慢指针刚好走到中间。
    ListNode* endOfFirstHalf(ListNode*head)
    {
        ListNode* fast=head,*slow=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode*head)
    {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr)
        {
            ListNode*nextNode=curr->next;//暂存下一个节点
            curr->next=prev;//将下一个节点指向上一个
            prev=curr;//存储当前节点作为上一个节点
            curr=nextNode;//将curr指向下一个节点
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr)
        {
            return true;
        }

        ListNode*firstHalfEnd=endOfFirstHalf(head);
        ListNode*secondHalfEnd=reverseList(firstHalfEnd->next);
        
        ListNode*p1=head;
        ListNode*p2=secondHalfEnd;
        
        bool res=true;
        while(p2!=nullptr)
        {
            if(p1->val!=p2->val)
            {
                res=false;
                break;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return res;
    }
};
