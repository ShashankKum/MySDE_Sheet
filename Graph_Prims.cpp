//Minimum spanning tree using prims is somewhat similar of dijkstras we use a min heap priority queue,keeping the smallest edge at first to pop(),
  in this we mark the nodes as true once traversed and add the minimum edges first.
//NOTE: Time taken for insertion of each element in priority queue takes O(logn) time if it is implemented using heap(done for stl).
//Time complexity is O((V+E)logV),prims is a greedy algorithm.

class Solution{
	public:
	bool bo[1002];
	int result=0;
	// Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.

    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
        memset(bo,false,sizeof(bo)); //intitally all are unvisisted
        q.push({0,0}); //0 is considered to be the root vertex and its distance inititalized to 0
        //first element is weight as in general it is sorted based on first element
        while(!q.empty()){
          pair<int,int> p=q.top();  //returns first element in queue
          int a=p.first,b=p.second; //a is weight and b is node
          q.pop();
          if(!bo[b]){ //since the same vertex acn be adjacent of multiple so it can be pushed multiple times in queue so check for false before processing
          bo[b]=true;
          result+=a; //keep on adding the smallest weight
          
          for(int i=0;i<adj[b].size();i++){ //for loop is more feasible as iterator cant traverse vector of vector, but it can traverse vector pair
              int u=adj[b][i][0],wt=adj[b][i][1];
              if(!bo[u]){
                  q.push({wt,u});
              }
          }
          }
        }
        return result;
    }

};
