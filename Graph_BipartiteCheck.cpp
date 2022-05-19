//To check if a graph is bipartite or not we need to check if vertexes for each edge do not lie in the same set.
//To achieve it we can check if it is possible to colour the graph with two different colours or not.

class Solution {
public:
    int b[100002];
    bool isSafe(vector<int>adj[],int col,int i){
        for(int k=0;k<adj[i].size();k++){
            if(b[adj[i][k]]==col)
            return false;
        }
        return true;
    }
    bool dfs(vector<int>adj[],int v,int i){
        if(i==v)
        return true;
        for(int c=1;c<=2;c++){
            if(isSafe(adj,c,i)){
                b[i]=c;
                if(dfs(adj,v,i+1))
                return true;
                b[i]=-1;
            }
        }
        return false;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    memset(b,-1,sizeof(b));
	    return dfs(adj,V,0);
	}
};
