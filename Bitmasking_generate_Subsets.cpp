                                                                 //2^n is same as 1<<n
                                                       //To check if kth bit of n is 1 -> (i&1<<k)!=0

//Generate all subsets of a vector
//BITMASKING
//Here time complexity will be O((2^n)*n)

int main() {
    int n,k;
    cin>>n;              //number of elements in vector/array
	vector<int> v(n);    //create vector of size n
	for(int i=0;i<n;i++)
	   cin>>v[i];
	vector<vector<int>> ans;
	int subset_num= 1<<n; //no of subset generated is 2^n(i.e 1<<n),as for each index it can be taken or not
	for(int i=0;i<subset_num;i++){
	    vector<int> a;  //vector to store one subset
	    k=0;
	    while(k<n){
	        if((i&1<<k)!=0)  //check if kth bit is 1 or not, 1 means we need to take element at that index
	          a.push_back(v[n-1-k]);  //if bit at kth index is 1 than push the same
	        k++;                      //check for k[0,n-1], as index goes from 0->n-1
	    }
	    ans.push_back(a);  //push all 2^n subsets one by one
	}
	for(int i=0;i<ans.size();i++){   //print all the 2^n subsets stored in vector of vector
	    for(int j=0;j<ans[i].size();j++)
	        cout<<ans[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
}

//Time to generate all substring can be braught down to O(2^n) using recursion

vector<vector<int>> ans;
void recur(int i,vector<int> a,vector<int> v){
    if(i<0){
        ans.push_back(a);
        return;
    }
    a.push_back(v[i]);
    recur(i-1,a,v);
    a.pop_back();
    recur(i-1,a,v);
}
