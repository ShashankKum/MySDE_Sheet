//In this we need to find max (j-i) from an array such that arr[j]>arr[i]
//It is a simple solution Which will use O(N) time and O(N) space, as we are using stack .
//In stack from back we will store the element such that at right of it there are o elements greater than it.
//So the stack will basically have decreasing order.
//now we will loop over the array and if arr[s.top()]>=arr[i] we will pop from stack and check further or else we will continue further in array.


class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        if(n==1)  return 0;
        stack<int> s;
        s.push(n-1);
        int ans=0,cur_dif;
        for(int i=n-2;i>=0;i--){   //we will push the values only when it is greater than prev(moving back to front)
            if(arr[s.top()]<arr[i])
               s.push(i);
        }
        for(int i=0;i<n;i++){                               //once element is popped it will never be inserted again.
            while(!s.empty() && arr[s.top()]>=arr[i]){
                cur_dif = (s.top()-i);
                ans = max(ans,cur_dif);
                s.pop();
            }
            if(s.empty())  return ans;
        }
        return ans;
    }

};