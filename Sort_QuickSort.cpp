//in this we always make first element as pivot,search its correct position by placing all elements less than pivot in left half and greater in right half
  now we do the same for both the halves left and right.
//we make a final swap of pivot only when j has crossed i.
//It will take O(NlogN) average time but in worst case time becomes O(N^2) .

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(high>low){ //we atleast have two elements to process
        int j=partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int i=low,j=high,pivot=low;
       while(j>i){ //make pivot reach its correct position
           while(arr[i]<=arr[pivot] && i<=high)
           i++;
           while(arr[j]>arr[pivot] && j>=low)
           j--;
           if(j>i)
           swap(arr[i],arr[j]);
       }
       swap(arr[pivot],arr[j]);
       return j;
    }
};