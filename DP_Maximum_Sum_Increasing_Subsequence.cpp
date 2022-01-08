class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
        int a[n],l,ma;
        a[0]=arr[0];
        ma=a[0];
        for(int i=1;i<n;i++){
            l=arr[i]; //even if i'th element is the smallest element till now
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    if(a[j]+arr[i]>l) 
                        l=a[j]+arr[i];
                }
            }
            a[i]=l; //we keep on storing the max sum possible in a[]
            ma=max(ma,a[i]); //it will give the maximum sum that has occured till now
        }
        return ma;
	} 
};