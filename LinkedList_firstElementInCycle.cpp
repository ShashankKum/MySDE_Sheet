//To find the point where cycle begins we can use hash set,we will be checking if the particular node already exists in the hash set,return it as answer
//and if it does not insert it and move forward.
//But this approach will take O(N) extra space and O(N) time.
//To optimise it we will use the tortoise method of fast and slow pointers it will take O(N) time and O(1) extra space.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL; //edge cases to be covered first
		
        ListNode *slow,*fast,*newNode;
        slow=fast=head;
        while(fast!=NULL && fast->next!=NULL){ //to get the collision point for slow and fast pointer
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)  //once they collide take a pointer to head move head and slow by one and once they collide return any one of them
            {
            newNode=head;
            while(newNode!=slow)
            {
                slow=slow->next;
                newNode=newNode->next;
            }
            return slow;
            }
        }
		
        return NULL; //this is the case if there is no cycle in the list
    }
};