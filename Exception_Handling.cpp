//An exception is an unexpected problem that occurs during runtime of the program.
//the part in which exception occurs is kept in the try block and the part to handle it is in catch block.
//exception can be handled but error cant,like accessing array out of bounds is also an exception.

#include<bits/stdc++.h>
using namespace std;

int main(){
	int numerator,denominator,result;
	cin>>numerator>>denominator;
	try{
		if(denominator==0)
		throw denominator;  //it will direct to catch, line below the throw will not work
	    result=numerator/denominator; //the line in which exception can occur is added in try block to prevent it
    }
    catch(int e){
    	cout<<"Not a valid numerator"<<endl;
	}
	cout<<result;
	return 0;
}