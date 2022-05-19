//In this we try to get it done in O(N) time complexity using O(N) space.
//We use two maps one for pattern and one for window in string, once all chars are found we remove one from left and search for it in right part.
//We keep on modifying the min_length of window and on basis of it we take the substring for minimum length.

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(p.size()>s.size())  return "-1";
        map<char,int> pat;
        map<char,int> str;
        for(auto x:p)  pat[x]++;
        int cnt=0,l=p.size(),mi_ln=999999,start=0;
        int st,ln;
        string ans="-1";
        for(int i=0;i<s.size();i++){
            str[s[i]]++;
            if(str[s[i]]<=pat[s[i]]) //if all characters are yet not complete from pattern
                 cnt++;
            if(cnt==l){
                //cout<<start<<" "<<i<<endl;
                //remove the extra characters from the left
                while(str[s[start]]>pat[s[start]] || pat.find(s[start])==pat.end()){  //till no char from pattern is found
                    str[s[start]]--;
                    start++;
                }
                if((i-start+1)<mi_ln){
                    mi_ln=min(mi_ln,(i-start+1));
                    st=start; ln=i-start+1;  //update starting index of subarray and its length
                }
                str[s[start++]]--;  //remove the first matched char and again repeat the above steps
                cnt--;
            }
        }
        ans=s.substr(st,ln);
        return ans;
    }
};