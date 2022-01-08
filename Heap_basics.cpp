//Heap is a data structure in which root node is always greater or less than child nodes. If root node is always greater than child node it is max heap and if root is 
  less than child node it is min heap.
  
//priority_queue is implemented using binary heap,by default it is max heap...priority_queue <int> q...top element will always be greatest
//priority_queue using min heap...priority_queue <int,vector<int>,greater<int>>...top element will always be smallest
//priority queue has..pop()->deletes top most element, push()->adjusts element in the stack based on the order..top()->returns top most element
//pop() and push() operations takes O(logN) time and top() takes O(1) time in priority_queue.
//priority queue can be used in cases where elements are continuously being pushed and every times it need to be sorted so for doing this each time using sorting
  we will need O(NlogN) time but for priority_queue each time it will only take O(logN) time.
  
//If question has Kth element as term and it needs smaalest or largest value, or it involves sorting we can understand that we need to use heap.

//Heap or priority_queue is also used to do frequency sort(get the frequencies in map and than push it in priority_queue of pairs,to get it sorted based on frequency).