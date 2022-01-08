//We have to get it base 62.
//In this we add the char at [n%62] index and each time divide the n by 62, we repeat it till we 
//have n!=0.than we reverse the string.

class Solution{
public:	
	// Function to generate a short url from integer ID
	string idToShortURL(long long int n) {
	    char arr[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	    string str="";
        while(n){
            str+=arr[n%62];
            n=n/62;
        }
        reverse(str.begin(),str.end());
        return str;
	}
};

long int shortURLtoID(string shortURL) 
{ 
    long int id = 0; // initialize result 
  
    // A simple base conversion logic 
    for (int i=0; i < shortURL.length(); i++) 
    { 
        if ('a' <= shortURL[i] && shortURL[i] <= 'z') 
          id = id*62 + shortURL[i] - 'a'; 
        if ('A' <= shortURL[i] && shortURL[i] <= 'Z') 
          id = id*62 + shortURL[i] - 'A' + 26; 
        if ('0' <= shortURL[i] && shortURL[i] <= '9') 
          id = id*62 + shortURL[i] - '0' + 52; 
    } 
    return id; 
} 