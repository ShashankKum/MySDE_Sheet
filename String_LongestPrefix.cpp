//In this first look if the first character matches in all string and if yes add it in empty string(s) 
//than do the same for second character and so on, whenever no match is there break the loop.
//It will take O(n*(sizeOfSmallestString)) time and O(1) extra space.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        char c;
        if(strs.size()==0) return s;
        if(strs.size()==1) return strs[0];
        int k=0;
        bool flag=1;
        while(true){
            c=strs[0][k];
        for(int i=1;i<strs.size();i++){
            if(k>=strs[i].size()) {flag=0; break;}
            if(strs[i][k]!=c) return s;
         }
            if(flag==0) break; //if flag i.e character not found, break the entire loop
            s+=c;
            k++;
        }
        return s;
    }
};