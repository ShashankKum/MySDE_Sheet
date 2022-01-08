//In this to get the minimum cost path we use recursion in which we try moving right and bottom recursively for each block.
//And than we take min cost obtained from both the movements.
//In order to remove overlapping sub-problems we use memoization using 2d matrix.

class Solution {
public:
    vector<vector<int>> ans;
    int recur(vector<vector<int>>& grid,int i,int j){
        if(i>=grid.size() || j>=grid[0].size())  //if we move out of the block return infinity value so that this is not considered while taking min
            return 9999999;
        if(i==grid.size()-1 && j==grid[0].size()-1) //if we reach our destination than simply return the value at that block
            return grid[i][j];
        if(ans[i][j]!=-1)
            return ans[i][j];
        int r=grid[i][j]+min(recur(grid,i,j+1),recur(grid,i+1,j)); //we take min of right or bottom movement
        ans[i][j]=r;
        return ans[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        ans.resize(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return recur(grid,0,0);
    }
};