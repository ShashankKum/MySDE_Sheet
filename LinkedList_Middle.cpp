//General solution is to traverse through the list and count the number of elements and than reach there, but it will take O(2*N) time.
//using tortoise method it can be done in O(N/2) time.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast,*slow;
        fast=slow=head;
        while(fast!=NULL && fast->next!=NULL){ //in this while(fast->next!=NULL && fast!=NULL) will give runtime error for even entries as first left side
            fast=fast->next->next;   //will be executed in while loop than right so if fast will reach NULL initially than there is no meaning of fast->next
            slow=slow->next;
        }
        return slow;
    }
};