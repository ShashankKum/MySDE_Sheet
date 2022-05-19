//To get a topological order it is necessary that we dont have a cycle in directed graph.
//For topological sort the vertices must be printed in such a order that for any edge (u,v) u must come before v...
//In order to do it we do a dfs traversal and push the node in stack if all its edges are traversed, so the first pushed node will be the nodes with zero
  degree i.e having no adjacent nodes, than the node from which it is coming...so if we reverse the order we will get a topological sort..so we pop
  elements one by one from stack and push it in vector.
//Topological sorting is only done for Directed Acyclic Connected graph(DAC)

class Solution{
	public:
	bool b[10002];
	stack <int> s;
	void dfs(vector<int> adj[],int a){ //simple dfs traversal
	    b[a]=true;
	    auto it=adj[a].begin();
	    while(it!=adj[a].end()){
	        if(!b[*it])
	        dfs(adj,*it);
	        it++;
	    }
	    s.push(a); //once all its neighbours are traversed push it in stack
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector <int> v;
	    memset(b,false,sizeof(b));
	    for(int i=0;i<V;i++){ //since graph is directed we have to check for all vertices
	    if(!b[i])
	    dfs(adj,i);
	    }
	    while(!s.empty()){  //push all elements one by one in vector
	        v.push_back(s.top());
	        s.pop();
	    }
	    return v;
	}
};