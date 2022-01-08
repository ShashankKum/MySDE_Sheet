//to check for worst case we need to take the max of breaking at a point and not breaking at a point.
//to check the minimum moves we have to try at each point and than take the min at all considering the best position to start with.
//If an egg will break at i'th floor means it can also break from (i+1)'th floor so we will check for i-1'th floor next as we need min moves.
//drop(K-1,i-1)->if egg breaks at the particular floor than it means egg reduces by 1 and now it is sure that it will break from any of the above floors so we try for floors below it(i-1).
//drop(K,N-i) -> if egg do not breaks at this floor maens egg remain same and we have to check for floors above it.

class Solution {
public:
    int arr[100][10002];
    int drop(int K, int N){
      //Base case
        if(N==0 || N==1) //if the floor is zero it will only be the threshold floor as we need a solution in any case
        return N;
        if(K==1)  //whenever egg becomes 1 we have to start from end to check the threshold floor so will always take N moves.
        return N;
        if(arr[K][N]!=-1)
        return arr[K][N];
        int ans=99999;
        for(int i=1;i<=N;i++){
            int temp = 1+max(drop(K-1,i-1),drop(K,N-i)); //we take max as we need the value in worst case
            ans=min(temp,ans);
        }
        arr[K][N]=ans;
        return arr[K][N];  
    }
    int superEggDrop(int K, int N) {
        memset(arr,-1,sizeof(arr));
        return drop(K,N);
    }
};