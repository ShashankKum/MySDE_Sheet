//Median for a sorted array is the average of middle two elements if array length is even or middle element if array length is odd . 
//The logic is that we just need to get the middle element/s of sorted array.
//We decide to divide both the arrays such that the point of division becomes the middle element. cond -> (left1<=right2 && left2<=right1)
//Since the array is sorted and we need the point of division based on a condition so we use binary search.
//Even if we get the division point for first array(cut1) we can use it to get division point for second element(cut2).
//time taken to solve would be O(log(m+n)) since we are using binary search to achieve it.


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //This below condition is used to handle the case when nums1 size is 1 and nums2 is empty.
        if(nums2.size()<nums1.size())  return findMedianSortedArrays(nums2,nums1);
        
        int l1 = nums1.size(),l2 = nums2.size();
        int i=0,j=l1,IntMin = -1e7,IntMax = 1e7;
        int left1,left2,right1,right2;
        double median;
        
        while(i<=j){
            int cut1 = (i+j)/2;    //it will give the number of elements to be taken from first vector
            int cut2 = (l1+l2+1)/2-cut1;  //it will give the number of elements to be taken from second vector
 //left1 and left2 will be the end elements of first half of nums1 and nums2 and right1 and right2 will be the first elements of second half
            
            left1 = (cut1==0)?IntMin:nums1[cut1-1];    //it is the rightmost element of first half of nums1
            left2 = (cut2==0)?IntMin:nums2[cut2-1];    //it is the rightmost element of first half of nums2
            right1 = (cut1==l1)?IntMax:nums1[cut1];    //it is the leftmost element of second half of nums1
            right2 = (cut2==l2)?IntMax:nums2[cut2];    //it is the leftmost element of second half of nums2
            
           
            if(left1<=right2 && left2<=right1){    //this is the condition when we can say we have the answer
                if((l1+l2)%2==0)  median = (max(left1,left2)+min(right1,right2))/2.0;
                else   median = (double)(max(left1,left2));
                break;
            }
            else if(left1>right2)    //it means we need to bring left1 back so move the division left side
                j = cut1-1;
            else  i = cut1+1;       //it is the case when left2>right1 in this we need to bring left1 to right 
        }
        return median;
    }
};