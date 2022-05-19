#include<bits/stdc++.h>
using namespace std;

//A library will consist of librarian,address,name,bookItems
//here librarian,member and server are the actors which can perform the use cases.
class Library{
    public:
      String name;
      Address address;
      vector<bookItem> books;
};
class Address{
    int pincode;
    int houseNo;
    string city,state,country;
    int sector;
};
//book items can be considered as the multiple copies of one book, so it will extend book
class book{
    string bookName;
    string IdNumber;
    vector<Author> authors;
    BookType bookType; //BookType is an enum here
};
class bookItem:public book{
    string BarCode;
    Rack rackPos;
    Date publishDate;
    BookStatus bookStatus;  //this is also enum
    BookFormat bookFormat;  //this is also enum
    Date issueDate;
};

enum BookType {SCI_FI,ROMANTIC,MATHS,DRAMA};
enum BookStatus {ISSUED,AVAILABLE,LOST,RESERVED};
enum BookFormat {HARDCOVER,JOURNAL,NEWSPAPER,PAPERBACK};

class Rack{
   int RowNumber;
   int Number;
};

//Now we will make classes for actors i.e user,librarian,server
//since author,user and librarian will have name so instead of creating seperate, will group them in Person parent classes

class Person{
    string FirstName;
    string LastName;
};

class Author:public Person{
    List<book> booksPublished;  
};

class SystemUser:public Person{ //SystemUser consists of Member and librarian
    string email;
    string phoneNumber;
    Account account;
}
class Member:public SystemUser{
    int BookCheckedOut;  //to keep count of number of books ISSUED
    Search searchObj;    //consist of searching based on parameters
    BookIssueService issueService;   //it will consist of return,issue,renew,reserve
}

class Librarian:public SystemUser{
    Search searchObj;
    BookIssueService issueService;
    
    //these will be the API calls
    public:
      void addBookItem(bookItem Item);
      bookItem deleteBookItem(string barcode);
      bookItem editBookItem(bookItem Item);
}

class Account{
    string userName;
    int accountId;
    string Password;
};

//Here searching based on parameters will be an API call
//To decouple the code we create object and than declare the functions in its class seperately
class Search{
    public:
       vector<bookItem> SearchParams(Author author);
       vector<bookItem> SearchParams(Date publishDate);
       vector<bookItem> SearchParams(BookType bookType);
};

class BookIssueService{
    FineService fineService;
    public:
       //there will be functions for issue,return,reserve,updateReserve
};

class FineService{
    public:
        Fine calculateFine(BookItem book,SystemUser user,int days);
};
class Fine{
    Date fineDate;
    BookItem book;
    SystemUser user;
    Double finevalue;
};

int main() {
	return 0;
}
