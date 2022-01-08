//Solution taking O(1) extra space.
//In this we first trim the string to remove all extra spaces than reverse the entire string and than reverse each word.
//In this we take care that the string is passed by reference so that all thge changes made are reflected in main function to
//reverse(s.begin()+a,s.begin()+b)...it will reverse the string from [a,b).

class Solution {
public:
    
    void trim(string &s){  //function for removing all extra spaces..front,end or in-between
        int l;
        while(s[0]==' ') //remove the trailing space from front
        s.erase(s.begin()); //delete spaces one by one
        
        l=s.size()-1;   
        while(s[l]==' '){  //remove the trailing space from front
           s.erase(s.begin()+l);
           l=s.size()-1;   //initialize it to last node after each deletion
        }
        
        int i=0;
        while(i<l){    //to remove extra spaces(more than one) in between words
        if(s[i]==' ' && s[i+1]==' '){
        s.erase(s.begin()+i);  //if a char is being deleted from string next character will come at same i
          l=s.size()-1;         //size will change after each deletion so we update it  
        }
        else i++; 
        }
    }
    
    void word(string &s,int i){ //again reverse all the words to get the required string
        int l=s.size(),a=0,b=0;
        while(i<l){
            if(s[i]==' '){ //we will never have it for last index as trailing spaces are already removed
                b=i-1;
                while(a<b){
                  swap(s[a],s[b]);
                  a++; b--;  
                }
                a=i+1;
            }
            i++;
        }
        b=l-1;
        while(a<b){ //used to reverse the last word
          swap(s[a],s[b]);
          a++; b--;  
        }
    }
    
    string reverseWords(string s) {
       int k=0,l=s.size()-1;
        trim(s);
        reverse(s.begin(),s.end()); //predefined function used to reverse string..(start index,end index)
        word(s,0);
        return s;
    }
};

//simplified code #leetcode_discus

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, j = 0, n = s.length();
        while (i < n && s[i] == ' ') i++;
        while (i < n) {
            int c = 0;
            while (s[i] != ' ' && i < n) s[j++] = s[i++], c++;
            reverse(s.begin()+j-c, s.begin()+j);
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            s[j++] = ' ';
        }
        return s.substr(0, j);
    }
};