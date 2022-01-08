class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	   bool b[V];
	   memset(b,false,sizeof(b)); //make all elements of the boolean array as false
	   vector <int> v;
	   int a;
	   queue <int> q;
	   q.push(0);
	   b[0]=true;
	   while(!q.empty()){
	       a=q.front();
	       q.pop();
	       v.push_back(a); //push the current accessed node in vector, and than traverse all its connected nodes
	       auto it=adj[a].begin();
	       while(it!=adj[a].end()){
	           if(!b[*it]){
	           q.push(*it);
	           b[*it]=true; //whichever element is being inserted make it as true
	           }
	           it++;
	       }
	   }
	   return v;
	}
};