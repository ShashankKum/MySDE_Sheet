  //O(NlogN) solution using O(1) extra space.
  //here the main logic is to increase the smaller and decrese the bigger so that the smallest and largest heights comes closest.
  //If we increment or decrement by same element in two numbers there difference still remains same.
  //so in worst case also the smallest element which we can imagine is arr[0]+k, as no point if we reduce arr[0] by k, and we need to do any one operation.
  //and largest in worst case is arr[n-1]-k
  //now we keep on checking by decrementing and incrementing each element to get the closest possible heights.
  
   
  class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        int smallest=arr[0]+k;
        int largest=arr[n-1]-k;
        int mi,ma;
        for(int i=0;i<n-1;i++){
            mi=min(smallest,arr[i+1]-k);
            ma=max(largest,arr[i]+k);
            if(mi<0)  continue;
            ans=min(ans,ma-mi);
        }
        return ans;
    }
};