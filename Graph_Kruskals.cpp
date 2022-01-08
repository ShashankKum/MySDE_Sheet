//Kruskals algorithm is used to find the minimum spanning tree, in spanning tree all vertices are connected using minimum edges, and if the cost is
  minimised we call it as minimum spanning tree.
//In kruskals we sort the edges by weight and than consider one by one the weights if cycle do not exists(find(a)!=find(b)).
//We also connect the smaller rank subtree to the greater rank subtree so that height is minimised.
//Time complexity is O(ElogE) for sorting the edges and O(Elogv) for detecting cycle using rank and path compression.

#include<bits/stdc++.h>
using namespace std;

int result=0,arr[10009],rnk[10009];

int find(int a){
    if(arr[a]==a)
    return a;
    else{
        int l=find(arr[a]);
        arr[a]=l;
        return l;
    }
}
void un(int a,int b,int wt){
    int l=find(a);
    int r=find(b);
    if(l==r)
    return;
    else{  //it means there is no cycle and we can take the wt
        result+=wt;
        if(rnk[l]>rnk[r])
            arr[r]=l;
        else if(rnk[r]>rnk[l])
            arr[l]=r;
        else{
           arr[l]=r;
           rnk[r]++;
        }
    }
}
int main() {                                                                                                                                                                                  
    //initially rank of all values is 0,as intitial ht is 0 
    for(int i=0;i<10009;i++){ //initially all element is the root node so parent of itself
    arr[i]=i;
    rnk[i]=0;
    }
	int e,v;
	cin>>e>>v;
	vector<vector<int>> vec;
	int a,b,wt;
	for(int i=0;i<e;i++){
	    cin>>wt>>a>>b;
	    vec.push_back({wt,a,b});
	}
	sort(vec.begin(),vec.end()); //by default it will be sorted based on first element that is weight here
	for(int i=0;i<e;i++){
	    int a=vec[i][1],b=vec[i][2];
	    un(a,b,vec[i][0]);
	}
	cout<<result;
	return 0;
}