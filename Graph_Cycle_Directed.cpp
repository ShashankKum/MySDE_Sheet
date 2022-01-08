//For directed graph we cant check cycle using disjoint set so we only have one method that is dfs traversal which will take O(V+E) time.
//In this we use two boolean arrays one used as normal to mark all the visisted nodes and other to keep track of currently visited nodes so that any of
  these nodes if encountered againg in loop we detect a cycle.
//For this unmark a node after all its adjacent componenets are visited.

class Solution {
public:
    bool b1[100002],b2[100002];
    bool dfs(vector<int> adj[],int a){
        b1[a]=b2[a]=true;
        for(int i=0;i<adj[a].size();i++){
            if(!b1[adj[a][i]]){ //if b1 is false means b2 will surely be false
                if(dfs(adj,adj[a][i]))
                return true;
            }
            else{
                if(b2[adj[a][i]])
                return true;
            }
        }
        b2[a]=false; //once all its adjacent nodes are traversed mark it false in recursive bool
        return false;
    }
	bool isCyclic(int V, vector<int> adj[]) {
	   	memset(b1,false,sizeof(b1));
	   	memset(b2,false,sizeof(b2));
	   	for(int i=0;i<V;i++){ //if any of the componenets of graph forms a cycle return true
	   	if(dfs(adj,i)) return true;
	   	}
	   	return false; //if no component is true than return false
	}
};