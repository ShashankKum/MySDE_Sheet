//Maximum possible sum in an array without considering adjacents.
//In this we use the idea of dynamic programming of recursion with memoization.
//We have two options either we can take an element(if we take than next element which might be considered is i+2'th) or else we exclude it
  and look for i+1'th element, once value for a particular pos is found we dont recur for it.
//It uses similar logic as that of Knapsack.


class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int ans[1000002];
	int dp(int arr[],int pos,int n){
	    if(pos>=n) return 0;
	    if(ans[pos]!=-1)  return ans[pos];
	    int r1=arr[pos]+dp(arr,pos+2,n);
	    int r2=dp(arr,pos+1,n);
	    return ans[pos] = max(r1,r2);
	}
	int findMaxSum(int *arr, int n) {
	     memset(ans,-1,sizeof(ans));
	     return dp(arr,0,n);
	}
};


//We can also do this question in O(N) time and O(1) spaec by making use of two variables which are regularly updated i.e incl and excl.
//incl will have the max sum including the current element and excl will have the sum excl the current element.
//incl = (excl_prev+arr[i]);  //excl_prev is the excl we hot in previous step
//excl = max(incl_prev,excl_prev);  //incl_prev is incl we got in previous step

//Same as it ->

arr[] = {5,  5, 10, 40, 50, 35}

  incl = 5 
  excl = 0

  For i = 1 (current element is 5)
  incl =  (excl + arr[i])  = 5
  excl =  max(5, 0) = 5

  For i = 2 (current element is 10)
  incl =  (excl + arr[i]) = 15
  excl =  max(5, 5) = 5

  For i = 3 (current element is 40)
  incl = (excl + arr[i]) = 45
  excl = max(5, 15) = 15

  For i = 4 (current element is 50)
  incl = (excl + arr[i]) = 65
  excl =  max(45, 15) = 45

  For i = 5 (current element is 35)
  incl =  (excl + arr[i]) = 80
  excl =  max(65, 45) = 65

And 35 is the last element. So, answer is max(incl, excl) =  80