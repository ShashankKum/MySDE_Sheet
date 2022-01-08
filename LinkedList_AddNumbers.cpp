//since the values are in reverse way we simply add the values and move the pointer forward,if any one list is NULL we only take value of other one and
//we move till both becomes NULL.
//we make use of sum(to store current sum) and car(to store current the previous carry). 
//It takes O(N) time and O(1) extra space.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *head=NULL,*ptr;
      int sum,car=0;
      while(l1!=NULL || l2!=NULL){
          ListNode *newNode = new ListNode;
          newNode->next=NULL;
          sum=((l1?l1->val:0) + (l2?l2->val:0))+car;  //making use of ternary operator to make the code concise
          newNode->val=sum%10;
          if(head==NULL){
              head=newNode;
              ptr=head;
              }
          else{
          ptr->next=newNode;
          ptr=newNode;
          }
          car=sum/10;
          l1?l1=l1->next:l1=NULL;
          l2?l2=l2->next:l2=NULL;
      }
        if(car>0){
        ListNode *newNode = new ListNode;
        newNode->next=NULL;
        newNode->val=car;
        ptr->next=newNode;
        }
        return head;
    }
};