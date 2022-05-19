//Finding all prime numbers till n using Seive of Erostheneses in O(log(logN) time.

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	bool b[n+1];
	memset(b,true,sizeof(b));
	for(int i=2;i*i<=n;i++){ 
	    if(b[i]==true){  //if false than already its multiples must have been covered
	     for(int j=i*i;j<=n;j+=i)  //make all multiples from square of i till n as false(not prime)
	         b[j]=false;
	    }
	}
	for(int i=2;i<=n;i++){  //print all prime numbers from 2 as 1 is neither prime nor composite
	    if(b[i]==true)
	    cout<<i<<" ";
	}
	return 0;
}


//GCD or HCF using Euclids algorithm. .. i.e if we subtract smaller number from larger number the gcd of remaining numbers will still be the same.
//An efficient solution is to use Euclidean algorithm which is the main algorithm used for this purpose. The idea is, GCD of two numbers doesn’t change 
//if smaller number is subtracted from a bigger number.

int gcd(int a,int b){
  if(a==0)
  return b;
  if(b==0)
  return a;
  if(a>b)
  return gcd(a-b,b);
  else
  return gcd(a,b-a);  //b is greater than or equal to a
}

//using mod in Euclids.
int gcd(int a,int b){
    if(b==0)
	return a;
	return gcd(b,a%b);
}

//LCM(a,b) = (a*b)/gcd(a,b);
