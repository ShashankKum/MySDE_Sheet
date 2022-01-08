//The naive approach is to shift node one by one to the head and make the shifted node as the head,but this will tak O(K*N) time k being number of shifts

//The optimised approach involves the logic that any multiple of N shifts will bring the same list back again so we only need to care for k%n shifts.
//make a loop of the list and than break it at n-k%n-1.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int n=0;
        ListNode* newNode=head;
        while(newNode!=NULL){
            n++;
            if(newNode->next==NULL)
            {
                newNode->next=head;
                break;
            }
            newNode=newNode->next; //connect end node to head to make a cycle
        }
        k=(n-k%n)-1; //it gives number of shifts required to break the loop so that it becomes right shifted
        newNode=head;
        while(k--)
            newNode=newNode->next;
        head=newNode->next;
        newNode->next=NULL;
        return head;
    }
};