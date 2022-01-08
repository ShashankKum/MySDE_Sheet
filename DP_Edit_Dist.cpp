//Recursive code
//We have to make s1 to s2, so if we replace we are making current character of s1 same as that of s2 so we move both i and j by 1 step
//if we insert than we are hypothetically adding one element in s1 so we keep i same and move j by 1 step for further comparison
//if we are deleting an element than we move i by 1 step thinking that current element is deleted and keep j as it is
//now we take the minimum of all three operations

class Solution {
public:
    int edit(int i,int j,string s1,string s2){ //i and j are the current indexes of s1 and s2 respectively
        //Base case
        if(i==s1.size())
            return s2.size()-j; //we do insertion for these many times
        if(j==s2.size())
            return s1.size()-i;  //we do deletion for these many times
        if(s1[i]==s2[j])
        return edit(i+1,j+1,s1,s2);
        else{
            int l=1+edit(i,j+1,s1,s2); //insert
            int m=1+edit(i+1,j,s1,s2); //delete
            int r=1+edit(i+1,j+1,s1,s2); //replace
            return min(l,min(m,r));
        }
    }
    int minDistance(string word1, string word2) {
        return edit(0,0,word1,word2);
    }
};

//memoized version
class Solution {
public:
    int arr[501][501];
    int edit(int i,int j,string s1,string s2){ //i and j are the current indexes of s1 and s2 respectively
        //Base case
        if(i==s1.size())
            return s2.size()-j; //we do insertion for these many times
        if(j==s2.size())
            return s1.size()-i;  //we do deletion for these many times
        if(arr[i][j]!=-1)
            return arr[i][j];
        
            if(s1[i]==s2[j])
        return arr[i][j]=edit(i+1,j+1,s1,s2);
        else{
            int l=1+edit(i,j+1,s1,s2); //insert
            int m=1+edit(i+1,j,s1,s2); //delete
            int r=1+edit(i+1,j+1,s1,s2); //replace
            return arr[i][j]=min(l,min(m,r));
        }
    }
    int minDistance(string word1, string word2) {
        memset(arr,-1,sizeof(arr));
        return edit(0,0,word1,word2);
    }
};