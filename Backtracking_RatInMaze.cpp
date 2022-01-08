//In backtracking we generally have undo condition that is we reach a point where it becomes invalid so we come back(backtrack)...as in case of rat in a
  maze problem where we had blocks in the way.
//but if the similar problem do not have blocks or do not have left and up movements we can solve it using simple recursion and dynamic(memoization)
  approach.
  
//In this we can only move right and down and we dont have any blockage.
class Solution {
public:
    int board[101][101];
    int path(int i,int j,int m,int n){
        //base case
        if(i==m && j==n) return 1; //reaches the destination
        if(i>m||j>n) return 0; //moves out of the grid
        //recursion
        if(board[i][j]==0)  //being 0 means its not traversed still
        return board[i][j]=(path(i,j+1,m,n)+path(i+1,j,m,n));
        else
        return board[i][j];
    }
    int uniquePaths(int m, int n) {
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 board[i][j]=0;
             }
         }
         return path(0,0,m-1,n-1);
    }
};


//In Rat in a Maze problem we have to move from first to the end of the matrix and print all the paths.
//For this we use backtracking,we mark the current position as visited and than visit left right up down of that position, and after all neighbours
  are visited we unmark it so that other position can visit it ones its neighbours are done, we do it so that in a single traversal we do not traverse
  a position twice.
//as other backtracking problems in this also we use...DO,RECUR,UNDO concept.

class Solution{
    vector<string> v;
    public:
   bool isSafe(int i,int j,int n,vector<vector<int>> &m){
        if(i>n || j>n || i<0 || j<0) //out of maze
        return false;
        if(m[i][j]==0) //any block is encountered
        return false;
        return true;
    }
    void path(vector<vector<int>> &m, int i,int j,int n,string s,vector<vector<int>> &visit){
        if(i==n-1 && j==n-1){
            v.push_back(s);
            return;
        }
		//do
        visit[i][j]=1; //marked as visited
		//recur
        if(isSafe(i,j-1,n-1,m)&&visit[i][j-1]==0) //left
         path(m,i,j-1,n,s+'L',visit);

        if(isSafe(i,j+1,n-1,m)&&visit[i][j+1]==0) //right
         path(m,i,j+1,n,s+'R',visit);
         
        if(isSafe(i-1,j,n-1,m)&&visit[i-1][j]==0) //up
         path(m,i-1,j,n,s+'U',visit);
         
        if(isSafe(i+1,j,n-1,m)&&visit[i+1][j]==0) //down
         path(m,i+1,j,n,s+'D',visit);
        //undo
        visit[i][j]=0; //once all its neighbours are traversed marked is at not visited for others
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s="";
        vector<vector<int>> visit(n, vector<int>(n+1,0)); //set all values to 0
        if(m[0][0]==0) return v;  //if the start position itself is 0
        path(m,0,0,n,s,visit);
        sort(v.begin(),v.end());
        return v;
    }
};