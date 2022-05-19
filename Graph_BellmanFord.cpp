//Relax all edges |V| - 1 times. A simple shortest path from src to any other vertex can have at-most |V| - 1 
// edges 
//It is a dynamic approach and will take O(V*E) time.

//Bellman-Ford stands good for Directed graph. any undirected graph is also a directed graph
//You just have to specify any edges {u, v} twice (u, v) and (v, u).
//But don't forget, that this also means any edge with a negative weight will count as a loop. As the Bellman-Ford algorithm ONLY works on graphs that don't contain any cycles with 
  negative weights this actually means your un-directed graph mustn't contain any edges with negative weight.

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define infy 999999

void bellman(int n,int e,vector <pair<pi,int>> v){
    int dist[n],j;
    bool flag=0;
    for(int i=0;i<n;i++)
    dist[i]=infy;
    dist[0]=0;
    for(int i=1;i<n;i++){   
        for(j=0;j<e;j++){
            int a=v[j].first.first;
            int b=v[j].first.second;
            int w=v[j].second;
            if(dist[b]>dist[a]+w)  //relaxation for each edge done n-1 times, where n is no of vertices
            dist[b]=dist[a]+w;
        } 
    }
    
     for(int j=0;j<e;j++){  //if after n-1 loops still value decreses means there is a negative edge cycle
            int a=v[j].first.first;
            int b=v[j].first.second;
            int w=v[j].second;
            if(dist[b]>dist[a]+w){
                flag=1;
            cout<<"Negative Cycle Found";
            break;
            }
        }
    
    if(flag==0){
        for(int i=0;i<n;i++)
        cout<<i<<" "<<dist[i]<<endl;
    }
    
}
int main(){
    int v,e;
    cin>>v>>e;
    int a,b,w;
    vector <pair<pi,int>> V;
    for(int i=0;i<e;i++){
        cin>>a>>b>>w;
        V.push_back({{a,b},w});
    }
    bellman(v,e,V);
    return 0;
}