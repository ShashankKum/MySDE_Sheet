//files are used to store data permanently.
//ifstream and ofstream are classes used to perform input and output operations in a file and both these classes are present in fstream header file.
//ifstream is a class(user defined data type) which is used to represent input file stream and is used to read information from files.
//fstream is a class(data type) which represents file stream generally, and has the capabilities of both ofstream and ifstream which means it can
  create file,write information to files,and read from files, but in this to write or read we need to use ios::out amd ios::in respectively.
  ex: fstream obj("xyz.txt",ios::out), but we do not need it in ofstream as it is specially for output.

#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main() {
	
	char a[100];
	cin.getline(a,100);  //getline will even take spaces in between until there is a new line
	//here obj(it can take any name) is the object of ofstream class, ofstream class(user defined data type) is used to create files and to write information to files.
	//here ios::app will make append mode active so whenever we run the program new line is added without removing previous one, we can also write a text in program by typing in the file.
	ofstream obj("file.txt");  //this will open the file 
	for(int i=0;i<10;i++)
	obj<<"what is in the name"<<endl;  //we can also write information taken input from user obj<<a;
	obj.close(); //to close the file
	
	//now for reading from the file
	ifstream obj1("file.txt");
	char arr[100];
	while(!obj1.eof()){ //it will print till we reach the end of file
	obj1.getline(arr,100);
	cout<<arr<<endl;
    }
    obj1.close();
    
	return 0;
	
}
