
//In this we we create a min heap(having smallest element at top), we than push all the elements of vector in it, and if size 
//increases k we pop the top() element, as these elements will be smaller than the kth largest.

//Time for push and pop in priority_queue(implemented using heap is O(logN), so as the heap will any time have atmost k elements
//time taken will be O(Nlogk), as we have to do the same for N elements in the vector.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int,vector<int>,greater<int>> q;
        auto it=nums.begin();
        while(it!=nums.end()){ //repeting it for all elements in vector
            q.push(*it);
            if(q.size()>k)
                q.pop();
            it++;
        }
        return q.top(); //final top element will be our answer
    }
};