//Time complexity of heap sort will be O(NlogN) for both average and worst case, time taken for haepify of leaf node is O(1) and for root node is O(logN)
  so heapify average and worst time complexity will be O(logN), first we create a heap from almost complete binary tree(given inout array)..for this we
  move from bottom to up as all below nodes will be arranged as we move up, but if we do from up, as we go down the heap structure will get dstroyed
  can check in [1,3,2,4,5,7,9], but there is no use of doing heapify operatiom for leaf node so we will go from [n/2-1,0].
//so creating heap will take O(n/2*logn) time.
//now we delete node from root and place it at end now our new heap will be n-1, so doing it repetedly will sort out array this will take O(n*logn) time.
//so total time will be O(NlogN).

class Solution
{
    public:
    void heapify(int arr[], int n, int i)  {
      int large=i;
      int l=2*i+1;
      int r=2*i+2;
      if(l<n && arr[l]>arr[large])
      large=l;
      if(r<n && arr[r]>arr[large])
      large=r;
      if(large!=i){
          swap(arr[large],arr[i]);
          heapify(arr,n,large);  //we will recur for any position which is destroyed.
      }
}
    
    public:
    void heapSort(int arr[], int n)
    {
        for(int i=n/2-1;i>=0;i--) //for creating heap
        heapify(arr,n,i);
        for(int i=n-1;i>=0;i--){  //for sorting used a created heap.
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
};
