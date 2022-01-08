#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pi pair<int,int>

void dijkstra(int n,vector <pi> *arr,int x)
{
    pi a;
    int b,i;
    vector <int> dist(n+1,1000);
    dist[x]=0;
   bool bo[n+1];
   memset(bo,false,sizeof(bo));
   priority_queue <pi,vector<pi>,greater<pi>> q;
   q.push(make_pair(0,x));
   while(!q.empty())
   {
       a=q.top();
       q.pop();
       b=a.second;
       if(bo[b]==false)
       {
           bo[b]=true;
           for(i=0;i<arr[b].size();i++)
           {
               if(bo[arr[b][i].second]==false)
               {
                   int u=arr[b][i].first;
                   int w=arr[b][i].second;
                    if(u+dist[b]<dist[w])
                   dist[w]=(u+dist[b]);
                  q.push(make_pair(dist[w],w));
               }
           }
       }
   }
   for(i=0;i<n;i++)
   cout<<i<<" "<<dist[i]<<endl;
}
int main() {
	int e,v;
	cin>>e>>v;
	int a,b,wt;
	vector <pi> arr[v+1];
	while(e--)
	{
	    cin>>a>>b>>wt;
	    arr[a].pb(make_pair(wt,b));
	    arr[b].pb(make_pair(wt,a));
	}
	dijkstra(v,arr,0);
	return 0;
}
