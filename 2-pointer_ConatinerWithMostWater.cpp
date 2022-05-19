//This problem (Container with max water)is different from trapping rainwater since in this the heights are not block and they are vertical lines, 
  In this we need to find the area which can hold max water summing up the gaps between the vertical lines,
  No area above the vertical line is considered as it is a negligible thin line.
//In trapping rainwater we need to get the max area water can be held over each block and we need to get the sum of it, for this we need
  lmax and rmax for each block.
//This is solved in O(N) time and O(1) space.


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int lh,rh,max_w=0;
        while(l<r){                                   //we loop over till l is less than r since till this all the possible answers would have been covered
            lh = height[l];  rh = height[r];          //set the heights of element at current left and right end
            max_w = max(max_w,(min(lh,rh))*(r-l));    //update the max water area each time
            (lh<rh)?l++:r--;     //the one either lh or rh which is smaller for that the max area is already covered so we increase the pointer
        }
        return max_w;
    }
};