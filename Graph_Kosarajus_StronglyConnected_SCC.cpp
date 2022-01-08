//We use kosarajus algorithm to find the number of strongly connected elements.
//Strongly connected graph means that we can traverse between any pair of that graph or to say after traversal each vertex will finally reach to itself.
//For this first we do a dfs traversal for each node and after all the adjacent nodes are visited of any node we push it back into stack.
//than we create a new array of vector storing the transpose of graph (having all the edges connected opposite to the original one).
//now we do dfs traversal for each node popped out from stack, and the number of dfs traversal will be our answer.
//At first we will do dfs traversal for each node beacuse the graph can also be disconnected or such that we cant reach from 0th node to all other 
  nodes. In this the first pushed elements in the stack will be for first dfs traversal and than next few for other and so on.

class Solution{
	public:
	bool b[5002];
	stack <int> s;
	int ans=0;
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    void dfs( vector<int> adj[],int a){
        b[a]=true;
        for(int i=0;i<adj[a].size();i++){
            if(!b[adj[a][i]])
            dfs(adj,adj[a][i]);
        }
        s.push(a);
    }
    void new_dfs( vector<int> n[],int a){
        b[a]=true;
        for(int i=0;i<n[a].size();i++){
            if(!b[n[a][i]])
            dfs(n,n[a][i]);
        }
    }
    int kosaraju(int V, vector<int> adj[]) {
        memset(b,false,sizeof(b));
        for(int i=0;i<V;i++){
            if(!b[i])
            dfs(adj,i);
        }
        vector<int> n[V]; //used to store the transpose of the graph
        for(int i=0;i<V;i++){  //we reverse the edges
            auto it=adj[i].begin();
            while(it!=adj[i].end()){
                n[*it].push_back(i);
                it++;
            }
        }
        memset(b,false,sizeof(b)); //make the boolean array false again
        while(!s.empty()){ //pop element one by one and do dfs for each
            int a=s.top();
            s.pop();
            if(!b[a]){
            ans++; //the number of new dfs traversals will give us the answer
            new_dfs(n,a);
            }
        }
        return ans;
    }
};