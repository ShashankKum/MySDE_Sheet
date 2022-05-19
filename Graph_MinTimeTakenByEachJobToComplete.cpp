//In this we have that each job takes only unit time and it can be completed only when the previous jobs to it are completed.
//If we have an edge {1,2} it means that 2 can be completed only when 1 is done.
//In this we first create inDegree for each node that is by this we can know how many vertices are pointing to it.
//we start with the vertices which have inDegree 0, and push them in queue and than we keep on decreasing inDegree for each node as it is
  visited, and once the inDegree becomes 0, push it in queue, repeat it till size of queue becomes 0.
//It will form an undirected graph with no cycle.
//The time complexity for this is O(V+E).
  


#include<bits/stdc++.h>
using namespace std;


int main() {
	int v,e,a,b;
	cin>>v>>e;
	int inDegree[v+1];
    memset(inDegree,0,sizeof(inDegree));
	vector<int> arr[v+1];
	//create inorder array 
	for(int i=1;i<=e;i++){
	    cin>>a>>b;
	    arr[a].push_back(b);
	    inDegree[b]++;             //since we have a->b so we increase inDegree by 1
	}
	queue<int> q;
	int ans[v+1];
	//if inDegree for any node is 0 push it in queue to start with it and time consumed will be 1 for them
	for(int i=1;i<=v;i++){
	    if(inDegree[i]==0){
	        q.push(i);
	        ans[i]=1;
	    }
	}
	//do level order traversal and once a node is incountered decrement its inDegree
	//queue will have the nodes only whose current inDegree has become 0
	while(!q.empty()){
	    int x=q.front();
	    q.pop();
	    for(auto node:arr[x]){
	        inDegree[node]--;
	        if(inDegree[node]==0){
	            q.push(node);
	            ans[node]=ans[x]+1;
	        }
	    }
	}
	for(int i=1;i<=v;i++){
	    cout<<ans[i]<<" ";
	}
	return 0;
}