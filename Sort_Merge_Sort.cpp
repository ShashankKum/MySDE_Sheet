//In merge sort we repetedly break the array(hypothetically) in smaller parts(each time the new partition is divided in two new subparts based on m).
//when only one element is left we merge the both subparts,now this subpart is sorted so we merge it with its other half and so on.
//Merge sort will take O(NlogN) time both in best and worst case unlike quick which is O(NlogN) in best and O(N^2) in worst case.

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)  //this is used to merge two sorted array,as array is broken in parts based on m
    {
       int l1=m-l+1,l2=r-m;  //main area to concentrate is this limit
       int a[l1],b[l2];
       int i,j,k;
       for(i=0;i<l1;i++)
       a[i]=arr[l+i];  //it will have values [l,m]
       for(i=0;i<l2;i++)
       b[i]=arr[m+1+i];  //it will have values [m+1,r]
       i=0,j=0,k=l;
       while(i<l1 && j<l2){ //copy values till one of the a[] or b[] is entirely traversed
           if(a[i]<=b[j]){
           arr[k]=a[i];
           k++; i++;
           }
           else{
           arr[k]=b[j];
           k++; j++;
           }
       }
	   //only one out of the two arrays will be left
       while(i<l1){  //if any element is left copy it directly
           arr[k]=a[i];
           k++; i++;
       }
       while(j<l2){ //if any element is left copy it directly
           arr[k]=b[j];
           k++; j++;
       }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        }
    }
};