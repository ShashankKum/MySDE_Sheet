#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void recur(int arr[],vector<int> v,int i){   //check if all digits are unique or not
    if(i<0){
        map<int,int> mp;
        int n=v.size();
        bool flag=true;
        for(int k=0;k<n;k++){
            int z=v[k],a;
            while(z>0){
                a=z%10;
                //cout<<a<<" "<<z<<endl;
                mp[a]++;
                if(mp[a]>1){
                    flag=false;
                    return;
                }
                z=z/10;
            }
        }
        ans.push_back(v);
        return;
    }
    v.push_back(arr[i]);
    recur(arr,v,i-1);  //element is taken
    v.pop_back();
    recur(arr,v,i-1);  //element is excluded
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	   cin>>arr[i];
	vector<int> v;
	recur(arr,v,n-1);
	for(int i=0;i<ans.size();i++){
	    for(int j=0;j<ans[i].size();j++)
	        cout<<ans[i][j]<<" ";
	        cout<<endl;
	}
	return 0;
}
