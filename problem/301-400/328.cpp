/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr)
        {
            return head;
        }
        ListNode*p1=head;
        ListNode*p2=head->next;
        ListNode*temp=p2;
        while(p1->next!=nullptr&&p2->next!=nullptr)
        {
            p1->next=p2->next;
            p1=p1->next;
            p2->next=p1->next;
            p2=p2->next;
        }      
        p1->next=temp;
        return head;
    }
};
