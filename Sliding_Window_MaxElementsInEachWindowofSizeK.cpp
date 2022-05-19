//In this there is a sliding window of size k and we need to find the max elements in each sliding window in O(N) time.
//It might look that it is taking time more than O(N) but here each element is being added and removed at most 2 times.
//For this we make use of deque of size k in which we can push and pop from both the sides.
//We maintain it such that the front element is always max and back element being min.
//Each time we want to push an element in deque we pop elements from back until those are smaller than cur since if we encounter bigger element
  in right than no use of smaller element in left.
//But if element is smaller we simply push it.
//We also keep on popping element from deque from front if it matches with the removed element from window.


class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> q;  //In this dequeue max value will be at front and min at back
        vector<int> ans;
        if(k>n) return ans;
        for(int i=0;i<k;i++){
             while(!q.empty() && q.back()<arr[i])  //remove the 
                  q.pop_back();
            q.push_back(arr[i]);
        }
        ans.push_back(q.front());
        for(int i=k;i<n;i++){
            if(q.front()==arr[i-k])  //remove front value as window moves forward
                  q.pop_front();
            while(!q.empty() && q.back()<arr[i])
                  q.pop_back();
            q.push_back(arr[i]);
            ans.push_back(q.front());
        }
        return ans;
    }
};