//In this we swap the adjacent nodes of the list, ex 1st with second 2nd and 3rd with 4th, but not 2nd with 3rd, In O(N) time and O(1) space.

class Solution {
public:
    ListNode* swap(ListNode* head){
        if(head==NULL)  return NULL;     //conition in which it reaches end
        if(!head->next) return head;     //condition in which the last pair has only one node
        
        //Swap takes place here
        ListNode *second = head->next,*new_head = second->next;
        second->next = head;
        
        //connect one pair to other, by connecting new head and tail
        head->next=swap(new_head);
        return second;
    }
    ListNode* swapPairs(ListNode* head) {
        return swap(head);
    }
};