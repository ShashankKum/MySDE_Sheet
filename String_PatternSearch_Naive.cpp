class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0; //if pattern is NULL return 0
        bool flag;
        int n=haystack.size(),j,i;
        int m=needle.size();
        if(m>n) return -1;  //if pattern is bigger than the string than no chance
        for(i=0;i<n;i++){
            flag=0;
            for(j=0;j<m;j++){
                if(haystack[i+j]!=needle[j]){
                flag=1;
                break;
                }
            }
            if(flag==0) return i; 
        }
        return -1;
    }
};