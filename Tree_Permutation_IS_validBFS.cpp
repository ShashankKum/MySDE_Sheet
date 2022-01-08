//Check if the given permutation is a valid BFS of a given Tree

//To do this we require a queue of sets and a map of (int,vector<int>) and a map of (int,int).
//in this as vertices are not continuously from 1->n so we use map<int,vector<int>> rather than using vector<vector<int>> to store them.
//we traverse through each element of the array(permutation, which we need to check if it is a BFS traversal),check if it is present in the set present at front of queue,
//if not present we simply return false as this permutation is not possible, if present we than push all its respective childrens in a set and push it back in queue.
//We than increment i and repeat the same process for all other elements in array, and if all are traversed without returning false finally return true.


#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp; //used to store children of each node
map<int,int> b;          //used to mark visited node

bool check(int arr[],int n){
    int i=0;
    queue<set<int>> q; //creating queue of sets where each set has all children of a parent
    set<int> s;
    s.insert(arr[i]);
    q.push(s);
    while(!q.empty() && i<n){
        if(q.front().find(arr[i])==q.front().end())  //if cur element is not present in set return false
            return false;
         
        if(b[arr[i]]==1)  //if element is already visited and it again appeared as cur element return false
        return false;
        b[arr[i]]=1;   //if element is found in the set, and not marked initially mark it as visited
       
        s.clear();                  //insert the childrens of current node in a set and than push the set in queue 
        auto it=mp[arr[i]].begin();
        while(it!=mp[arr[i]].end()){
            if(b.find(*it)==b.end())
            s.insert(*it);
            it++;
        }
        if(s.size()>0)  //if no children is there of current node(empty set) no need to push it
        q.push(s);
        
        q.front().erase(arr[i]);  //after all its children are inserted erase the node
        if(q.front().size()==0)  //if set becomes empty pop it from queue
        q.pop();
        
        i++;  //increment i, to move to next element as cur element
    }
    return true;
}
int main() {
    int a,b,n,e;
	cin>>n>>e;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	while(e--){
	    cin>>a>>b;
	    mp[a].push_back(b);
	}
	if(check(arr,n))
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
