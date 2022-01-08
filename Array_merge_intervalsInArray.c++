//sort the interval pair kept in vector form and than merge the overlapping intervals making use of a pair.

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector <pair<int,int>> v;
    vector <pair<int,int>> p;
	pair <int,int> pi;
	int a,b,c;
	for(int i=0;i<n;i++)
	{
	    cin>>a>>b;
	    v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	
	pi=v[0];
	for(int i=1;i<n;i++)
	{
	    if(pi.first<=v[i].first && v[i].first<=pi.second)
	    {
	        if(v[i].second>pi.second)
	        pi.second=v[i].second;
	    }
	    else
	    {
	       p.push_back(pi);
	       pi=v[i];
	    }
	    if(i==n-1)
	    p.push_back(pi);
	}
	auto it=p.begin();
	while(it!=p.end())
	{
	    cout<<it->first<<" "<<it->second<<endl;
	    it++;
	}
	return 0;
}
