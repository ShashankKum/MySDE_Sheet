
//String is defined in main function,so here we have to pass by refrence,so that the changed string is printed or else the original one will be printed.

#include<bits/stdc++.h>
using namespace std;

void recur(string &s,int i,int n){
    if(i==n/2)
    return;
    swap(s[i],s[n-i-1]);
    recur(s,i+1,n);
}
int main() {
	string s;
	cin>>s;
	int n=s.size();
	recur(s,0,n);
	cout<<s;
	return 0;
}

//in this we declare the string globally so here we dont need to pass by refrence.
//The changes made in recurring functions are made permanent.

#include<bits/stdc++.h>
using namespace std;

string s="SHASHANK";
void recur(int i,int n){
    if(i==n/2)
    return;
    swap(s[i],s[n-i-1]);
    recur(i+1,n);
}
int main() {
	int n=s.size();
	recur(0,n);
	cout<<s;
	return 0;
}
