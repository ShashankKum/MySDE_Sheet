 //In this we need to get the minimum possible A[i]*i sum where i->[0,N-1] taking all forms of clockwise rotation in O(N) time, and O(1) space.
 //In this the trick is that when we rotate array the last element goes to first and remaining move right by one position just.
 //So we can store the result of previous rotation and above it we can use this formula -> prod = prod-(A[j]*(N-1))+(sum-A[j])
 

 int max_sum(int A[],int N)
 {
    if(N==1)  return 0;
    int prod=0,ans,sum=0;
    for(int i=0;i<N;i++){
        prod += A[i]*i;
        sum+=A[i];
    }
    ans=prod;  
    for(int j=N-1;j>=1;j--){
       prod = prod-(A[j]*(N-1))+(sum-A[j]);
       ans = max(ans,prod);
    }
    return ans;
 }