//Hash value for a character can be seen from (1-26),if hash value for any window in the string matches with that of pattern than only we check the characters in that window.
//window size is equal to the size of pattern
//It is also called as rolling hash because of moving window
//The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm)
//Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same.

class Solution {
public:
    
    int strStr(string haystack, string needle) {
        int n=needle.size(),m=haystack.size();
        if(n==0) return 0;
        if(n>m) return -1; //if size of pattern is greater than string
        if(haystack.substr(0,n)==needle) return 0;
        int hash_value=0,v=0,a=0,l;
        bool flag;
        for(int i=0;i<n;i++) v+=(haystack[i]-'a'+1);
        for(int i=0;i<n;i++)  //get the hash value of the pattern
        hash_value+=(needle[i]-'a'+1);
        
        for(int i=n;i<m;i++){
            v+=(haystack[i]-haystack[a]); //we subtract the first value of window and add the new value
            a++;
            if(v==hash_value){
                l=i-n+1; //l taken to the first element of the current window
                flag=1;
                for(int j=0;j<n;j++){
                    if(haystack[l+j]!=needle[j]){
                        flag=0; break; 
                    }
                }
                if(flag==1) //if it happens that means there is a complete match
                    return l;
            }
        }
        return -1;
    }
};