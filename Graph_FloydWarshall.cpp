//In floyd warshall we first create a 2d array cotaining 0 values in diagonal(as distance of a node from itself is zero if no self loop exists),
  all other distances are infinity, than we set the distance between the given edges.
//First we check the distance between wny two nodes via first node than second node and so on till all nodes,the shortest path will be updated.
//This algorithm can also be used to check negative edge cycle(cycle in which sum of all connected edge comes out to be -ve), if after all relaxations 
  if any diagonal element comes out to be negative.
//It is based on Dynamic Programming and uses O(v^3) time complexity.


#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define infy 999999
#define v 4 //vertices needs to be globally defined as we need it while passing 2d array as parameter

void floyd(int arr[][v]){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++)
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
        }
    }
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    int e;
    cin>>e;
    int arr[v][v];
    int a,b,w;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==j)
            arr[i][j]=0;
            else
            arr[i][j]=infy;
        }
    }
    for(int i=0;i<e;i++){
        cin>>a>>b>>w;
        arr[a][b]=w;
    }
    floyd(arr);
    return 0;
}