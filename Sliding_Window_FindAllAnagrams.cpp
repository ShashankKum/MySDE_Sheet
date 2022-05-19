Sliding Window(fixed) Topics->
1. max/min subarray of size k
2. count of occurence of anagrams
3. max of all subarrays of size k

//In this we need to find all start positions of all anagrams possible in a string.
//For this we need to use sliding window since the size to be looked after will always be equivalent to pattern size.
//Time taken will be O(N) and space will be O(1)  since size of vector is fixed i.e 26.


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        //using (char-'a') we can fix the indexes for ech char between [0,25]
        vector<int> goal(26),cur(26);  //while declaring vectors by default there initial values are 0
        int n = p.size();
        for(int i=0;i<n;i++)  goal[p[i]-'a']++;       //fix the characters for the pattern
        for(int i=0;i<s.size();i++){
            cur[s[i]-'a']++;                         //add a new character
            if(i>=n)  cur[s[i-n]-'a']--;             //remove the old one for which window crosses over i.e (i-n)     
            if(goal==cur)   ans.push_back(i-n+1);   //if characters of cur window matches that of pattern we have an answer
        }
        return ans;
    }
};

//It can also be solved using map but it will be more complicated.

//In this we make use of sliding window technique,in which we have a window of length pattern(p), so whenever the window moves only
//change is the first element of window is getting removed and one new element is being added at end,so we just need to change both,
//instead of taking care of entire new window.
//We have two maps, mp1 is mapped for pattern and mp is mapped for slidding window, so whenever (mp=mp1) we have a solution.
//Time complexity is O(n)*O(26) i.e O(n).

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map <char,int> mp,mp1;
        vector<int> v;       //it will store the start indexes of all the anagrams present in string s
        int l=p.size(),n=s.size();
        if(l>n) return v;
        bool flag;
        for(int i=0;i<l;i++)  //make a hash table of pattern
            mp1[p[i]]++;
        for(int i=0;i<(l-1);i++)  //make hash table of first (l-1) elements of string
            mp[s[i]]++;
        for(int i=0;i<(n-l+1);i++){
            if(i>0) mp[s[i-1]]--;         //remove the first element of last window
            mp[s[i+l-1]]++;               //add the new element i.e ith (i+l-1)th element
            flag=0;                       //if flag remains 0 till end means mp==mp1 and we have a solution
            auto it=mp.begin();
            while(it!=mp.end()){          //here we check if both mp and mp1 matches
               if(mp[it->first]!=mp1[it->first]){  //if there is a mismatch make flag 1 and break the loop, we cant have a solution
                   flag=1;
                   break;
               }
                it++;
            }
            if(flag==0)         //if both the maps match(have the same frequency of characters) that means we have a solution
                v.push_back(i);
        }
        return v;
    }
};