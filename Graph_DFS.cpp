//Iterative solution for DFS.

class Solution {
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    bool b[V];
	    memset(b,false,sizeof(b));
	    b[0]=true;
	    vector <int> v;
	    int a;
	    stack <int> st;
	    st.push(0);
	    while(!st.empty()){
	        a=st.top();
	        st.pop();
	        v.push_back(a);
	        auto it=adj[a].begin();
	        while(it!=adj[a].end()){
	            if(!b[*it]){
	                st.push(*it);
	                b[*it]=true;
	            }
	            it++;
	        }
	    }
	    return v;
	}
};

//Recursive solution.

class Solution {
public:
    void dfs(int a,vector<int> &v,vector<int> adj[],bool b[]){
       v.push_back(a);
       b[a]=true;
       auto it=adj[a].begin();
	    while(it!=adj[a].end()){
	        if(!b[*it]){
	          dfs(*it,v,adj,b);
	        }
	        it++;
	    }
    }
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector <int> v;
	    bool b[V];
	    memset(b,false,sizeof(b));
	    dfs(0,v,adj,b);
	    return v;
	}
};