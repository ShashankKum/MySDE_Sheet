//In n queens problem we check for each position in a row, check if that position is safe or not and if it is safe we move to the next row and check for 
  its respective columns, we do till base case occurs(i.e i==n) in this case we print the matrix and return true if we need only one combination
  and return false if we need all so that all possiblities can be tried.
//In this also we follow the concept of do,recur and undo.

class Solution {
public:
    int board[10][10];
    bool isSafe(int i,int j,int n){
        for(int k=0;k<i;k++){ //checke for vertically up positions
            if(board[k][j]==1)
            return false;
        }
        int x=i;
        int y=j;
        while(x>=0 && y>=0){ //check the left upper diagonal
            if(board[x][y]==1)
            return false;
            x--; y--;
        }
        x=i;
        y=j;
        while(x>=0 && y<n){ //check the right upper diagonal
            if(board[x][y]==1)
            return false;
            x--; y++;
        }
        //if no elements found at any of these positions than it is safe
        return true;
    }
    
    bool queen(int i,int n,vector<vector<string>> &ans){
        if(i==n){ //we have found an answer set,base case
            vector<string> v;
            for(int i=0;i<n;i++){
                string s;
                for(int j=0;j<n;j++){
                    if(board[i][j]==1) //get the positions wherever queens were set
                        s.push_back('Q');
                    else s.push_back('.');
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return false; //if we need only one combination send true else send false
        }
        
        for(int j=0;j<n;j++){
            if(isSafe(i,j,n)){
                //do
                board[i][j]=1;
                //recur
                if(queen(i+1,n,ans)){
                return true;
                }
                //undo (if queen(i+1,n) holds false make the index again as 0)
                board[i][j]=0;
            }
        }
        //if we have travelled the entire row but we have not found any safe position
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j]=0;
            }
        }
        vector<vector<string>> ans;
        queen(0,n,ans);
        return ans;
    }
};