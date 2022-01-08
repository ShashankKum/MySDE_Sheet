//Recursion...if choices are available than we know we can write recursive code of it, like in this case we have choices like do we include item 1 in 
  knapsack or not and so on.
//To write a recursive code we need two things:
  1. Base condition -> the smallest sub problem which can exist will be our base condition.
  2. Choice Cycle -> like if weight of one element is less than the total available weight we will not take it but if weight is less than total weight
                     than we will take it.
//In recursive code the set on which we are performing operation will reduce step by step, as in this case the array.
//The time taken for simple recursive code will be same as brute force, so we optimize our recursive code to match the time complexity of DP(top down
  approach) by using a 2d matrix(process known as memoization)...in this values are being stored so if one value is already processed we dont need
  to find it again.


int arr[1002][1002]; //we will further intialize the entire globally declared array in main() as -1

int knapSack(int W, int wt[], int val[], int n) 
{ 
   //Base condition
   if(n==0 || W==0)
   return 0;
   
   if(arr[n][W]!=-1)
   return arr[n][W];
   
   if(wt[n-1]<=W)
   return arr[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1), knapSack(W,wt,val,n-1));  //two choices if wt is less or equal
   
   else if(wt[n-1]>W)
   return arr[n][W]=knapSack(W,wt,val,n-1); //only one choice
}

//We can also use recursion code to think the iterative version(top down approach), just replace n,w by i,j and knapsack by arr.

int knapSack(int W, int wt[], int val[], int n) 
{ 
    //Initialization same as base case in recursion
   int arr[n+1][W+1];
   for(int j=0;j<W+1;j++)
   arr[0][j]=0;
   for(int i=0;i<n+1;i++)
   arr[i][0]=0;
   
 //In place of n,w use i,j and in place of knapsack use arr
   for(int i=1;i<n+1;i++){
       for(int j=1;j<W+1;j++){
           if(wt[i-1]<=j)
           arr[i][j]=max(val[i-1]+arr[i-1][j-wt[i-1]],arr[i-1][j]);
           else if(wt[i-1]>j)
           arr[i][j]=arr[i-1][j];
       }
   }
   return arr[n][W];
}