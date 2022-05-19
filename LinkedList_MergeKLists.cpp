//This approach takes O(N*k) time and O(1) space as it is in place.
//In this we simply take two lists first merge them than using this merged list take it with third list and merge it and so on.
// L1+ l2 = L12, L12 + l3 = L13, L13+L4 = L14....and so on till all lists are traversed


class Solution {
public:
    ListNode* merge(ListNode* &head,ListNode *head1){
        if(head==NULL)  return head = head1;
        ListNode *temp = head,*prev = NULL;
        
        while(temp && head1){
            if(temp->val <= head1->val){  //since temp is less or equal we simply increment the pointer
                prev = temp;
                temp =temp->next;
            }
            else{                       //in this we need to add head1 before temp, since it is smaller
               ListNode *a = head1;
               head1 = a->next;
               a->next = temp;
               if(prev)   prev->next = a;
               if(!prev)  head = a;        //it means element is being added before head so we need to change head also
               prev = a;
            }
        }
        
        if(head1)                         //if head1 still do not reaches end just add it to temp
            prev->next = head1;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          if(lists.size()==0)   return NULL;
          ListNode *head = NULL;
          for(int i=0;i<lists.size();i++)
              merge(head,lists[i]);
        return head;
    }
};

//Optimized approach using priority queue.

//In this we push the head of each list in min heap, so each time we get the minimum, once we pop one pointer we push the next of it if it is available.
//It will take O(NlogK) time where N is the total number of elements and K is the number of list available, since in each time we will only have k elements in the heap.
//We  do it till no nodes are left or to say we reach the end of priority queue.


class Solution {
public:
    //this function used to create a min heap based on values, since we are using ListNode, or else we can simply use pair of {int,ListNode*}
    struct compare
    {
    bool operator()(ListNode* &a,ListNode* &b){
        return a->val>b->val;
    }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*,vector<ListNode*>,compare> pq;   //we create our min heap for the ListNode
        for(int i=0;i<lists.size();i++){     //we push the head nodes of each list in our min heap
            if(lists[i])
               pq.push(lists[i]);
        }
        ListNode* head=NULL,*temp;
        while(!pq.empty()){
            ListNode* cur = pq.top();
            pq.pop();
            if(head==NULL){
                head = cur;
                temp = cur;
            }
            else{
                temp->next = cur;
                temp = cur;
            }
            if(temp->next)
                pq.push(temp->next);
        }
        return head;
    }
};