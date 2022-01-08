//To get length of longest substring without any repeating character
//It is the most optimized approach with O(N) time complexity and O(N) space complexity(due to hash map storing characters).
//brute force approach will take O(N^2) time complexity making use of two pointers i and j ...i will traverse through the string and j will
  always begin from 0th index couting for non repeating continuous characters till i
//here store the recent indexes of char in map and move window slidder of l followed by r.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> mp;
        int l=0,r=0;  //window slidders
        int count,ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])==mp.end())   //search for s[i] last position
            {
                count= r-l+1;
                r++;
                mp[s[i]]=i;
            }
            else
            {
                if(mp[s[i]]>=l)
                {
                    l=mp[s[i]]+1;
                }
                count = r-l+1;
                r++;
                mp[s[i]]=i;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};