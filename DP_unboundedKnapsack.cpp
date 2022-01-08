//In Recursion we start from the end of array and than step by step think of reducing the array.
//It is unbounded knapsack where we can reuse the elements(Repeting elements).
//There are few problems based on it-> coin change problem(both 1&2),rod cutting problem

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        if(N==0 || W==0) //Base condition
        return 0;
        if(wt[N-1]<=W)
        return max(val[N-1]+knapSack(N,W-wt[N-1],val,wt),knapSack(N-1,W,val,wt));
        else
        return knapSack(N-1,W,val,wt);
    }
};

//Top Down approach thought using recursion approach.
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int arr[N+1][W+1];
        for(int i=0;i<=N;i++) //initialize
        arr[i][0]=0;
        for(int j=0;j<=W;j++)
        arr[0][j]=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]<=j) //in this case it can be included or not
                arr[i][j]=max(val[i-1]+arr[i][j-wt[i-1]],arr[i-1][j]);
                else
                arr[i][j]=arr[i-1][j]; //if weight cant be included
            }
        }
        return arr[N][W];
    }
};