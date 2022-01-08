//generating all subsets can be achieved via backtracking only and time taken will be O(2^n) and here we can't use dp, but if we just need to check if a substring exist or not we can use   backtracking

//In this we are given an array and we have to return true if any subset of it has sum equal to SUM.
//We first think of the recursive code and than using that we write the top down code for dynamic programming.
//Equal Sum Partition, Subset sum, Target sum all are related to 0-1 Knapsack.

bool subset(int nums[],int n,int sum){
    if(sum==0) return true;
    if(n==0 && sum!=0) return false;
    
    if(nums[n-1]<=sum) //if value is less than sum
    return (subset(nums,n-1,sum-nums[n-1])||subset(nums,n-1,sum)); //in this either we select or not
    
    else
    return subset(nums,n-1,sum);
}



bool subset(int nums[],int n,int sum){
    bool arr[n+1][sum+1];
    for(int i=0;i<n+1;i++) //when array is empty
    arr[i][0]=false;
    for(int j=0;j<sum+1;j++) //when sum is 0
    arr[0][j]=true;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(nums[i-1]<=j)
            arr[i][j]=(arr[i-1][j-nums[i-1]]||arr[i-1][j]);
            esle
            arr[i][j]=arr[i-1][j];
        }
    }
}