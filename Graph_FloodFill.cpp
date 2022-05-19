//Flood Fill Algorithm , solved with a time complexity of O(m*n) 
//In this we start with a source node and than we traverse to all its touching side neighbours and if the value is same as parent we colour 
//it with the same colour.


class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int col,int parent,vector<vector<bool>>& vis){
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || vis[i][j]==1 || image[i][j]!=parent)  return;
        vis[i][j]=1;                             //mark the current node as visited
        dfs(image,i-1,j,col,image[i][j],vis);
        dfs(image,i,j-1,col,image[i][j],vis);
        dfs(image,i,j+1,col,image[i][j],vis);
        dfs(image,i+1,j,col,image[i][j],vis);
        image[i][j]=col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> vis(image.size(),vector<bool> (image[0].size(),0));
        dfs(image,sr,sc,newColor,image[sr][sc],vis);
        return image;
    }
};