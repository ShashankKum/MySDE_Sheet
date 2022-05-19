//Merge List
//This is the tougher version where we do not use extra space


//In this we create a new list but use the previous nodes only to connect to prevent extra space
//Whenever we need to create a new node we need to create it using new keyword or else only refrence will be created.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)  return list2;
        if(list2==NULL)  return list1;
        ListNode *head=new ListNode;
        ListNode *n1=head;
        while(list1!=NULL && list2!=NULL){
            if(list1->val > list2->val){
                n1->next=list2;
                n1=list2;
                list2=list2->next;
            }
            else{
                n1->next=list1;
                n1=list1;
                list1=list1->next;
            } 
        }
        (list1==NULL) ? n1->next=list2 : n1->next=list1;
        return head->next;
    }
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2; //if any of the two lists are empty
        if(l2==NULL) return l1;
        
        ListNode *p=NULL,*head=l1; //Head will be the first index of merged list
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val > l2->val) //connect l2 before l1
        {
            ListNode *newNode;
            newNode=l2;
            l2=l2->next;
            newNode->next=l1;
            if(p!=NULL){
            p->next=newNode;
            p=newNode;
            }
            else{          //This is the case when first index(head) is being changed.
                p=newNode; //as any one of l1 or l2 will be smallest
                head=p;
                }
        }
        else
        {
        p=l1;
        l1=l1->next;
        }
    }
        if(l1==NULL) //after any one of the list id travelled
        p->next=l2;
        
        return head;
  }
};