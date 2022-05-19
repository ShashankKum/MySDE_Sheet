//Maximum sum combinations using two arrays in O(N) time using dp, such that if we take index k of arr1 we cant take index k of arr2
  and we cant even take consecutive indexes of any one array.
  
  This problem is based on dynamic programming. 

  //Let dp(i, 1) be the maximum sum of the newly selected elements if the last element was taken from the position(i-1, 1).
  //dp(i, 2) is the same but the last element taken has the position (i-1, 2)
  //dp(i, 3) the same but we didn’t take any element from position i-1
  
  dp(i, 1)=max(dp (i – 1, 2) + arr(i, 1), dp(i – 1, 3) + arr(i, 1), arr(i, 1) ); 
  dp(i, 2)=max(dp(i – 1, 1) + arr(i, 2 ), dp(i – 1, 3) + arr (i, 2), arr(i, 2)); 
  dp(i, 3)=max(dp(i- 1, 1), dp( i-1, 2) )
  
    int Max_Sum(int arr1[], int arr2[], int n)
    {
    // To store dp value
    int dp[n][2];
     
    // For loop to calculate the value of dp
    for (int i = 0; i < n; i++)
    {
        if(i==0)
        {
            dp[i][0] = arr1[i];
            dp[i][1] = arr2[i];
            continue;
        }
       dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + arr1[i]);
       dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + arr2[i]);
    }
     