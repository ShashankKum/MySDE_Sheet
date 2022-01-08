//code to reverse a linked list using three pointers.

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        return head;

        ListNode *p,*q,*r;
        p=q=r=head;
        q=head->next;
        if(q==NULL)
        return head;
        
        r=head->next->next;
        p->next=NULL;
        q->next=p;
        if(r==NULL)
        return q;
        
        p=q;
        q=r;
        r=r->next;
        while(r!=NULL)
        {
           q->next=p;
           p=q;
           q=r;
           r=r->next;
        }
        q->next=p;
        head=q;
        return head;
    }
};


//short code

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newNode=NULL;
        while(head!=NULL)
        {
            ListNode *my=head->next; //one node comming next to head
            head->next=newNode;
            newNode=head;
            head=my;
        }
        return newNode;
    }
};