//One brute force way is to use the selection sort method it will take O(N^2) time.
//We use the concept of graph and cycle to solve this problem, in O(NlogN) time and O(N) space.
//We create an array of pairs in which we store the elements of array with there indexes and than we sort it based on first element.
//So that we can see how many indexes were swapped to reach the sorted array.
//The indexes which were swappped will form a cycle and the number of swaps will be (length of cylce - 1)


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size(),k,l,ans=0;
	    bool b[n];
	    memset(b,false,sizeof(b));
	    pair<int,int> arr[n];
	    for(int i=0;i<n;i++){
	        arr[i].first=nums[i];
	        arr[i].second=i;
	    }
	    sort(arr,arr+n);   //array will get sorted based on first element
	    for(int i=0;i<n;i++){
	        if(arr[i].second==i || b[i]==true)
	            continue;
	        else{
	            k=i;  l=0;    //l will be used to get the length of cycles
	            while(b[k]==false){
	                b[k]=true;     //once the element is visited mark it as true
	                l++;
	                k=arr[k].second;   
	            }
	            ans+=l-1;   //no of swaps will be l-1 where l is the length of cycle
	        }
	    }
	    return ans;
	}
};