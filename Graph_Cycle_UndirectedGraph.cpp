//Cycle in an undirected graph can be detected using both dfs method and disjoint set but we prefer dfs as using disjoint time complexity will be O(E*logV)
//The program does a simple DFS Traversal of the graph which is represented using adjacency list. So the time complexity is O(V+E).
//In this we return true as soon as cycle is found(node is visited and is also not a parent node),once true is returned return the same for all.

class Solution {
public:
    bool b[100001];
    bool dfs(vector<int>adj[],int a,int parent){
        b[a]=true;
        auto it=adj[a].begin();
        while(it!=adj[a].end()){
            if(!b[*it]){
                if(dfs(adj,*it,a)) //if loop was found than recursively return true for each call
                return true;   //if false is returned keep on checking for other adjacent nodes too
            }
            else if(b[*it] && *it!=parent) //main trick is here
            return true;
            it++;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    memset(b,false,sizeof(b));
	    for(int i=0;i<V;i++){  //check for all as graph might consist of more than one components
	        if(!b[i]){
	        if(dfs(adj,i,i)) return true; 
	        }
	    }
	    return false;
	}
};