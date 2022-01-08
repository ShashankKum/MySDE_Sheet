//Variable size sliding window to get Longest Substring Without Repeating Characters.
//We do it using a hash table where we store the frequencies of char in current substring(i->j)
//Initially we set i and j as 0, we check in each step if copy of current char is already present, we increse i and do mp[s[i]]--,
//till the freq of current element becomes 0, and after this check we increment j and add freq of char in each iteration.
//we store a ma variable wich will store max substring length.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int i=0,j=0,ma=0;
        while(j<s.size()){
            if(mp[s[j]]>0){          //we have a duplicate in intitially traveled substring(i->j)
                while(mp[s[j]]!=0){  //till the duplicate copy of s[j] is removed from hash table, we increment i
                    mp[s[i]]--;
                    i++;
                }
            }
            mp[s[j]]++;
            j++;
            ma=max(ma,(j-i));
        }
        return ma;
    }
};