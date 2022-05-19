//In this we need to get the length of consecutive days for which stock price is <= current day price.
//To implement it in O(N) time we make use of stack, it will look as if it takes more than O(N) time but once a element is popped from stack it is not entered again.
//We pop till the element price is <= curr price.
//Each time we pop we need to update l to the index till which popped element has a series.
//It will take O(N) space.
//In each step we will also push the maximum span in vector.


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       if(n==1) return {1};
       stack<int> s;
       vector<int> v;
       int l;
       s.push(0);
       v.push_back(1);
       for(int i=1;i<n;i++){
           l=s.top();
           while(!s.empty() && price[s.top()]<=price[i]){
                l = s.top()-v[s.top()];
                s.pop();
           }
           if(s.empty())  v.push_back(i+1);
           else v.push_back(i-l);
           s.push(i);
       }
       return v;
    }
};