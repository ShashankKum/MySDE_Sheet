//To detect the next greatest element using stack to decrease time complexity from O(N^2) to O(N).
//In this case the array is circular.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> v;
        int k=nums.size(),l,m;
        l=k-2;
        while(l>=0){  //push all elements before the last element in the stack as array is circular,so the first element will come next to last.
            st.push(nums[l]);
            l--;
        }
        l=k-1;
        while(l>=0){   //do same for all the elements from end to first and push the respective values in vector
            m=0;
            while(!st.empty()) //check till the stack becomes empty or till you get a bigger element
            {
            if(st.top()>nums[l]){
                v.push_back(st.top());
                m=1;
                break; }
            else st.pop(); 
            }
            if(m==0) v.push_back(-1); //if not push -1
            st.push(nums[l]);
            l--;
        }
        //reverse(start_index, last_index);
        reverse(v.begin(),v.end());   //reverse the vector as the values pushed were from back to front
        return v;
    }
};