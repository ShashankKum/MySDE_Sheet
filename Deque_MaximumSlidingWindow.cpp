//In this we have a slidding window of size k,for each slide we need to push the maximum value present in that window range in the vector and return it.
//Trick1: If we have a bigger element than there is no use of any smaller element which is at its left,because when that element will come out of the 
         window the previous elements would have already came out.
//Trick2: But the elements entering new will always be of use because it might be that the previous bigger element will be left out of the window and
          the new enetered element will be the biggest in future.
//So we use Deque data structure,since we want operations from both end.
//We will always have the greatest element at front,since we will pop all elements smaller than the one entering new in the deque,so the first element
  will always be the largest value.We will store the indexes in deque to access the elements
//If i has crossed the index of front value we will pop : d.front_pop().

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> v; 
       deque<int> d;  //stores the indexes in descening order by value at that index, also following the order of latest entered at end.
        int i=0,j=-1,l=nums.size();
    
        while(j<l-1){
            if(j>=k-1) i++; //After the first window is comleted
            j++;
            if(j>k-1){      //pop the index if it comes out of the window
            if(d.front()<i) 
			d.pop_front(); 
            }
            while(!d.empty()){  //pop the values from end till the values are smaller than new
                if(nums[d.back()]<=nums[j])
                    d.pop_back();
                else break;
            }
            d.push_back(j); //the new element index will always be pushed
            if(j>=k-1)
            v.push_back(nums[d.front()]);
        }
        return v;
    }
};