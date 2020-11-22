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
 //by tianfangma
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode*p1=l1,*p2=l2,*last=l1;
        while(p1!=nullptr&&p2!=nullptr)
        {
            int temp = p1->val + p2->val + carry;
            p1->val=temp%10;
            carry=temp/10;
            last = p1;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1!=nullptr)
        {
            int temp = p1->val + carry;
            p1->val = temp%10;
            carry = temp/10;
            last = p1;
            p1=p1->next;
        }
        p1 = last;
        while(p2!=nullptr)
        {
            int temp = p2->val + carry;
            p1->next = new ListNode(temp%10);
            carry = temp/10;
            p2=p2->next;
            p1=p1->next;
            last = p1;
        }
        if(carry)
        {
            last->next = new ListNode(carry%10); 
        }
        return l1;
    }
};

//leetcode solution 
//simulate
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head = nullptr,*tail = nullptr;
        int carry=0;
        while(l1||l2)
        {
            int x1 = l1?l1->val:0;
            int x2 = l2?l2->val:0;
            int temp = x1+x2+carry;
            if(!head)
            {
                head=tail=new ListNode(temp%10);
            }
            else
            {
                tail->next=new ListNode(temp%10);
                tail=tail->next;
            }
            carry=temp/10;
            if(l1)
            {
                l1=l1->next;
            }
            if(l2)
            {
                l2=l2->next;
            }
        }
        if(carry)
        {
            tail->next=new ListNode(carry%10);
        }
        return head;
    }
};
