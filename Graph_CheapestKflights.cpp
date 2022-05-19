//In this we can think of approach similar to dijkstras but here we cant do relaxation, since if the smaller cost path has more than 
//k stops it wont be valid, so we need to check for other possibilities as well.

//here we have breaks array which will help us keep track of number of stops to reach that point, if its value is max means the respective
//node is yet not traversed.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;  //min heap,values in form {price,node_val,k}
        //create an adjacency list first to traverse
        vector<vector<int>> arr[n];    //values in form -> arr[from]={to,price}
        for(auto f:flights){
            arr[f[0]].push_back({f[1],f[2]});
        }
        q.push({0,src,0});                       //push the source node
        int breaks[n];                           //it is the array used to store the number of stops required to reach the node
        memset(breaks,102,sizeof(breaks));       //initialize it to max value
        while(!q.empty()){
            vector<int> v = q.top();
            int cost = v[0],node = v[1],stop = v[2];
            q.pop();
            if(node==dst)  return cost;
            //if previously we have reached the node using less no of breaks than no point in taking the new path, since we are using min heap so the price must also be smaller of previous path
            if(stop<breaks[node] && stop<=k){ 
                breaks[node]=stop;
                for(auto x:arr[node]){
                     q.push({cost+x[1],x[0],stop+1});
                } 
            }
        }
        return -1;
    }
};