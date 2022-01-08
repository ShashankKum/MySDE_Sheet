//Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
//If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
//Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
//We do this by using merge sort to bring dow time from O(N^2) to O(NlogN).
//We sort the array and while merging we check if a value at right subpart is smaller than the value of any index at left subpart than all other values right of left
  subpart will also be greater than it,so we increment the count (l1-i) times.

class Solution{
  public:
    long long ans=0;

    // Function to count inversions in the array.
    void merge(long long int arr[],long long l,long long mid,long long r){
        long long l1=mid-l+1,l2=r-mid;
        long long int a[l1],b[l2];
        for(long long i=0;i<l1;i++)
        a[i]=arr[l+i];
        for(long long i=0;i<l2;i++)
        b[i]=arr[mid+1+i];
        long long i=0,j=0,k=l;
        while(i<l1 && j<l2){
            if(b[j]<a[i]){
                ans+=(l1-i);
                arr[k]=b[j];
                j++; k++;
            }
            else{
                arr[k]=a[i];
                i++; k++;
            }
        }
        while(i<l1){
            arr[k]=a[i];
            i++; k++;
        }
        while(j<l2){
            arr[k]=b[j];
            j++; k++;
        }
    }
    void mergeSort(long long int arr[],long long l,long long r){
        if(l<r){
        long long int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
         mergeSort(arr,0,N-1);
         return ans;
    }

};