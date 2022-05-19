12#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define infy 999999

//In dijkstras if the node is 
//first value of priority queue is the largest and rest are arranged in non increasing order, push() can be used 
//to push the value at end in priority queue and pop() removes the first element from priority queue, top() also
//returns the first element, it is implemented using max heap.
//Here we are using modified priority_queue which is implemented using min heap storing values in non decreasing order.
//By doing this we keep in track that all short tracks are being traversed at first
//Dijkstras uses O(ElogV), and is the greedy algorithm as it works on getting the smallest cost edge each time.

void dijk(int v,vector <pi> adj[]){
    priority_queue <pi,vector<pi>,greater<pi>> q;
    q.push({0,0}); //0 dist for root node that is 0
    bool b[v];
    memset(b,false,sizeof(b));
    int dist[v];
    for(int i=0;i<v;i++) //set all values intially to infinity
    dist[i]=infy;
    dist[0]=0;
    while(!q.empty()){
        pi a=q.top();
        q.pop(); //remove the first val,node pair from priority_queue
        int val=a.second;
        if(!b[val]){  //multiple times the same node can be pushed so check if visited
         b[val]=true;
        auto it=adj[val].begin();
        while(it!=adj[val].end()){
             if(!b[it->first]){ //if node is visited means it has already attained its shortest path
                 if(dist[it->first]>(dist[val]+it->second)){ //relaxing
                 dist[it->first]=dist[val]+it->second;
                 }
                 q.push({dist[it->first],it->first});
             }
             it++;
         }
        }
    }
    for(int i=0;i<v;i++)
    cout<<i<<" "<<dist[i]<<endl;
}

int main() {
	int v,e,a,b,w;
	cin>>v>>e;
	vector <pi> adj[v];
	while(e--){
	    cin>>a>>b>>w;
	    adj[a].push_back({b,w});
	    adj[b].push_back({a,w});
	}
	dijk(v,adj);
	return 0;
}
