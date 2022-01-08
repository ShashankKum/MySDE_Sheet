//In first approach we push all elements of one list in the hash set and than traverse through the other list and whenever we get any node already 
//we can say that it is the intersection node.
//But this is not best approach as it takes O(N+M) time and O(N) extra space(hash set).

class Solution { 
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set <ListNode*> s;  //used unordered set so that searching and insertion time is O(1).
        ListNode *newNode=headA;
        while(newNode!=NULL){
          s.insert(newNode);
            newNode=newNode->next;
        }
        newNode=headB;
        while(newNode!=NULL){
        if(s.find(newNode)!=s.end())
                return newNode;
        newNode=newNode->next;
        }
        return NULL;
    }
};

//In this approach we reduce extra space to O(1). and time is same O(N+M).
//Keep in mind that by removing the additional nodes when we move together in both lists we will
//reach the junction.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1=headA,*l2=headB;
        //if any one list is empty than return NULL
        if(l1==NULL || l2==NULL) return NULL;
        while(l1!=l2){
           if(l1==NULL && l2==NULL) //it will be the case in second traversal of no intersection
            return NULL;            //list
            l1=l1->next;
            l2=l2->next;
            if(l1==NULL && l2!=NULL) l1=headB; //go to head of other list after first complete t
            if(l2==NULL && l1!=NULL) l2=headA; //traversal
        }
         return l1;  
    }
};

