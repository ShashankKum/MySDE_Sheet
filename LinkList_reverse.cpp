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

//recursive solution

class Solution {
public:
    ListNode* recur(ListNode *head,ListNode *temp){
        if(head==NULL)
            return temp;
        ListNode* new1=head->next;
        head->next=temp;
        temp=head;
        head=new1;
        return recur(head,temp);  //in recursion we return the function call so that the end returned value is recursively returned back
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        return recur(head,NULL);
    }
};