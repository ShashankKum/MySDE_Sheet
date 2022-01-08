//Time Complexity is O(m+n),O(m) for building the array keeping track of prefix suffix match and O(n) for the single traversal in string.
//Best example how array is created for suffix prefix match
//cabcaefgcabcabl
//[000120001234530]

class Solution {
public:
    //create prefix suffix array,representing the longest matched suffix
    void prefixSuffix(string &s,int arr[],int n){
        int i=1,len=0;
        arr[0]=0;
        while(i<n){
        if(s[i]==s[len]){
            len++;
            arr[i]=len;  i++;
        }
        else{
            if(len==0){
                arr[i]=0; 
                i++;
            }
             else
              len=arr[len-1]; //we do not increment i here
        }
        }
    }
    
    //check for pattern in string, whenever there is a mismatch see if there is a suffix prefix match in the traversed pattern.
    //if the match exists go to the next element of the suffix and start matching from there instead going back again in the string
    
    int strStr(string haystack, string needle) {
        int n=needle.size(),m=haystack.size();
        if(n==0) return 0; //if pattern is empty
        int arr[n];
        prefixSuffix(needle,arr,n); //to get an array containing length of suffix matching to current index
        int j=0,i=0,ans=-1; //ans returns the first index of string where matching begins
        bool flag=0; //flag 0 indicate that there is not even a single char match now
        while(i<m){
            if(haystack[i]==needle[j]){
                if(flag==0){
                   ans=i;
                   flag=1;
                }
                i++; j++;
                if(j==n) return ans; //if entire pattern is traversed means there is a match 
            }
            else{
                if(j==0) {i++; flag=0;} //if j reaches the first index of pattern make flag 0
                else{
                j=arr[j-1];
                ans=i-j;
                }
            }
        }
        return -1; //this will happen only when the complete pattern is not found
    }
};