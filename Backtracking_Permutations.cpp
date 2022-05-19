//Bactracking is basically an algorithm that finds the solution recursively, it builds subproblems recursively and rejects those which cant fulfill the 
  condition.
//In case of bactracking(recursion) we will just think for one subproblem and think that rest subproblems will be solved on its own recursively.
//in this we swap the element make the first element fix permute for the other part of string(not containing the swapped element),and do it recursively till
  i==j, and than we push the string back. 
//Before moving to other value of k we again swap back the string to have its original position.

//using stl
  sort(s.begin(),s.end());
  do{
	cout<<s<<" ";
  }while(next_permutation(s.begin(),s.end()));

//prints all permutations in lexicographical order
#include<bits/stdc++.h>
using namespace std;

void permute(string s,int i,int j,vector <string> &v){
    if(i==j){
    v.push_back(s);
    return
    }
    for(int k=i;k<=j;k++){
        //do
        swap(s[k],s[i]);
        //recur
        permute(s,i+1,j,v);
        //undo..if what is done needs to be corrected again
        swap(s[k],s[i]);
    }
}
int main() {
	int T;
	cin>>T;
	while(T--){
	    string s;
	    cin>>s;
	    vector <string> v;
	    int n=s.size();
	    permute(s,0,n-1,v);
	    sort(v.begin(),v.end());
	    auto it=v.begin();
	    while(it!=v.end()){
	        cout<<*it<<" ";
	        it++;
	    }
	    cout<<endl;
	}
	return 0;
}