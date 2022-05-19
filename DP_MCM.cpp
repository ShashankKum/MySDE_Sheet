//Matrix chain Multiplication
//the problems based on mcm type are...palindrome partitioning, scramble string, egg dropping problem.
//In these kind of questions we usually have an array or string and we take i at one end and j at one end. We move k from i to j and break at each value
  and than recursively call for each part(i->k,k+1->j),like in case of mcm we have to give brackets so we need to decide where to give.
//we store the value returned by both parts in temp integer and than return the maximum or minimum(as required) from all the divisions and return it.
  
//Format

 int format(int arr[],int i,int j){t-
 //base condition
   if(i>j)
   return 0;
   int temp,temp_ans=0;
 for(int k=i;k<j;k++){
   temp=format(arr,i,k)+format(arr,k+1,j);
   temp_ans=min(temp,temp_ans);
 }
  return temp_ans;
 }
 
 //Recursive code for MCM.
 //in this we place paranthesis at every possible interval and than recursively call for that interval and print the minimum value.
 //if an array [a,b] is given means we have only one matrix that is a*b so multiplication product will be 0. if we have [a,b,c] in this we keep 
   i at index 1 and j at last index,and the result will be arr[i-1]*arr[k]*arr[j].
   WE move k from i to j-1.
   
 class Solution{
public:
    int multiply(int arr[],int i,int j){ //i and j included
    if(i>=j) 
    return 0;
    int ans=99999999,mi;
        for(int k=i;k<j;k++){
            int l=multiply(arr,i,k);
            int r=multiply(arr,k+1,j);
            mi=l+r+(arr[i-1]*arr[k]*arr[j]);
            ans=min(ans,mi);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        if(N==2) return 0;
       return multiply(arr,1,N-1);
    }
};

//Memoized solution matching the time complexity of DP.
class Solution{
public:
    int a[100][100];
    int multiply(int arr[],int i,int j){ //i and j included
    if(i==j) 
    return 0;
    if(a[i][j]!=-1) //if any subarray is traversed first than use its value only
    return a[i][j];
    int ans=999999999,mi;
        for(int k=i;k<j;k++){
            a[i][k]=multiply(arr,i,k);
            a[k+1][j]=multiply(arr,k+1,j);
            mi=a[i][k]+a[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
            ans=min(ans,mi);
            a[i][j]=ans;
        }
        return a[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(a,-1,sizeof(a)); //initialized all elements to -1
        if(N==2) return 0;
       return multiply(arr,1,N-1);
    }
};