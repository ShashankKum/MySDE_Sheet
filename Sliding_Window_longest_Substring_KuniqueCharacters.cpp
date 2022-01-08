//Sliding Window -> Variable Length
//In this we need to get the longest substring with k distinct characters.

//Logic-> We need to use the map to store the frequency of characters ,we have i and j both initially set to 0,we keep on incrementing j till number of distinct characters becomes k,
//once it exceedes we increase i till cnt=k.


class Solution{
    public:
    int longestKSubstr(string s, int k) {
       int n=s.size(),i=0,j=0,cnt=0,ans=0,l;
       unordered_map<int,int> mp;
       while(j<n){
           if(mp[s[j]]==0)
           cnt++;
           mp[s[j]]++;
           j++;
           while(cnt>k){
               mp[s[i]]--;
               if(mp[s[i]]==0)
               cnt--;
               i++;
           }
           if(cnt==k){
               l=(j-i);
               ans=max(ans,l);
           }
       }
       if(ans==0) return -1;
       return ans;
    }
};