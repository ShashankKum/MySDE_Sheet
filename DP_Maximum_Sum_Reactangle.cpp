//Maximum sum rectangle problem useus similar approach as Kdanes algorithm for maximum subarray sum in 1D , it is just that it is used in 1D and we need to modeify it to be used in 2D.

//For this we fix left and right pointers for columns in matrix which will use two loop and take O(n^2) time complexity.
//Than we use a 1D array of size=no of rows, and keep the addition for each rows ,from left to right and than use kadanes algorithm in this 1D array,to get the answer.
//In order to remove overlapping sub-problems we use memoization using 2d matrix.

void findMaxSum(int M[][COL])
{
    // Variables to store the final output
    int maxSum = INT_MIN,
                 finalLeft,
                 finalRight,
                 finalTop,
                 finalBottom;
 
    int left, right, i;
    int temp[ROW], sum, start, finish;
 
    for (left = 0; left < COL; ++left) {             //sets left column boundry
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));
 
        for (right = left; right < COL; ++right) {   ////sets left column boundry
 
            // Calculate sum between current left
            // and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];
 
            // Find the maximum sum subarray in temp[].
            // The kadane() function also sets values
            // of start and finish. So 'sum' is sum of
            // rectangle between (start, left) and
            // (finish, right) which is the maximum sum
            // with boundary columns strictly as left
            // and right.
            sum = kadane(temp, &start, &finish, ROW);  //function made to apply kadanes algo
 
            // Compare sum with maximum sum so far.
            // If sum is more, then update maxSum and
            // other output values
            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
}