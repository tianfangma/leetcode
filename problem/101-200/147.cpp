/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //inserting sort
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode *dummyNode=new ListNode(0);
        dummyNode->next=head;
        ListNode *lastSorted = head,*curr=head->next;
        while(curr!=nullptr)
        {
            if(curr->val>=lastSorted->val)
            {
                lastSorted=lastSorted->next;
            }
            else
            {
                ListNode*prev=dummyNode;
                while(prev->next->val<=curr->val)
                {
                    prev=prev->next;
                }
                lastSorted->next=curr->next;
                curr->next=prev->next;
                prev->next=curr;
            }
            curr=lastSorted->next;
        }
        return dummyNode->next;
    }
};
