//to check wether a linked list is palindrome or not using O(1) extra space and O(N/2(middle)+ N/2(reverse_laterHalf)+ N/2(check palindrome)).


ListNode* mid(ListNode* head)
{
    ListNode *slow,*fast;
    slow=fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        if(fast!=NULL) //done to get the first middle when count is even
            slow=slow->next;
    }
    return slow;
}
ListNode* reverse(ListNode* m)
{
    ListNode *d=NULL;
    while(m!=NULL)
    {
        ListNode *my;
        my = m->next;
        m->next=d;
        d=m;
        m=my;
    }
    return d;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        ListNode *my,*newNode,*ptr;
        my=mid(head);  //received pointer to mid node
        newNode=reverse(my->next); //return first pointer of reversed node
        my->next=newNode;  //connect both to get half normal and half reversed list
        ptr=my->next;
        while(ptr!=NULL){
            if(ptr->val!=head->val)
                return false;
            ptr=ptr->next;
            head=head->next;
        }
        return true;
    }
};