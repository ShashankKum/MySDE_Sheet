//Using Tortoise Method(use of slow and fast pointers) to reduce the time to O(N) and O(1) space complexity.
//Else we have to traverse to find the total number of nodes and than traverse again and delete (n-k+1)th node,it will take O(2*N) time and O(1) space.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode *fast,*slow;
        ListNode *newNode=new ListNode(); //making a dummy node since first node can be deleted
        newNode->next=head;
       fast=slow=newNode;
        while(n--)   //shift fast so that the difference b/w fast and slow is n
            fast=fast->next;
        while(fast->next!=NULL){  //than move both by one step
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *temp;
        temp=slow->next;  //store the node to be removed
        if(temp==head)
            head=head->next;
        slow->next=slow->next->next;
        delete(temp);   //remove the unwanted space
        return head;
    }
};