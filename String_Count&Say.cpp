class Solution {
public:
    string solve(string s){  //function which returns the count and say sequence for any given string
        string ans="";
        char c=s[0];
        int i=0,k=0;
        while(i<s.size()){ //to build a string with count of consecutive digits
            if(s[i]!=c){
              ans+=(to_string(k)+c); //to_string used to convert int to string
              k=1; c=s[i];
            }
            else k++;
            i++;
        }
        ans+=(to_string(k)+c);
        return ans;
    }
    string countAndSay(int n) {
        string s="1";
        if(n==1) return s;
        n--;
        while(n--) //to loop for n-1 times
        s=solve(s);
        return s; //returns the final string
    }
};