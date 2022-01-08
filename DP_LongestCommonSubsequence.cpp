//Topics based on Longest Common subsequence
  largest common substring,shortest common subsequence,largest repeating subsequence,sequence pattern matching,largest palindromic subsequence,
  largest palindromic substring,count of palindromic substring and many more
//function to find longest common subsequence
//if the last values match than increment the count by 1 and decrement the size of strings by 1
//if last values do not match take the max of reducing the first array by one and second array by 1
//brute force using recursion which can be reduced using 2d matrix in recursion to store the traversed values.
//all dp recursion codes consists of base case and choice diagram
//MEMOIZATION IS ALSO KNOWN AS BOTTOM UP

int lcs(int x, int y, string s1, string s2){
    //base condition
    if(x==0 || y==0) 
    return 0;
    //choice diagram
    if(s1[x-1]==s2[y-1])
    return 1+lcs(x-1,y-1,s1,s2);
    else
    return max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
}

//Top Down approach

//just replace x and y by (i,j), ans lcs by array 
int lcs(int x, int y, string s1, string s2){
    //base condition
    int arr[x+1][y+1];
    for(int i=0;i<=x;i++)
    arr[i][0]=0;
    for(int j=0;j<=y;j++)
    arr[0][j]=0;
    
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1])
            arr[i][j]=1+arr[i-1][j-1];
            else
            arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }
    return arr[x][y];
}