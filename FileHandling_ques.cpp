//We read input from file and print the letters with there frequencies in ascending order.

#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main() {
	
	string s;
	cin>>s;  
    ofstream obj("file.txt");
    obj<<s<<endl;  //here endl is used so that we get the output,otherwise from file we will read string of 0 size
    ifstream obj1("file.txt");
	string s1;
	obj1>>s1;
    cout<<s1;
    map<char,int> mp;
    for(int i=0;i<s1.size();i++)
    mp[s1[i]]++;
    vector <pair<int,char> > v;
    map<char,int>::iterator it=mp.begin();
    while(it!=mp.end()){
    	v.push_back(make_pair(it->second,it->first));
    	it++;
	}
	sort(v.begin(),v.end());
	vector <pair<int,char> >::iterator it1=v.begin();
	while(it1!=v.end()){
		cout<<it1->second<<" "<<it1->first<<endl;
		it1++;
	}
	return 0;
}