//In this we will have a time comlexity of 2^(2n) i.e 4^n since in each position we can fit two braces i.e either open or close.
//We use backtracking to generate all the combinations possible.
//if right brace is less than left than only we place right or else in all other cases we go for left only, once r==n we have one answer added.


class Solution {
public:
    vector<string> ans;
    void recur(string s,int n,int l,int r){
        if(l>n) return;
        if(r==n){
            ans.push_back(s);
            return;
        }
        if(r<l){
           recur(s+')',n,l,r+1);
           recur(s+'(',n,l+1,r); 
        }
        else  recur(s+'(',n,l+1,r);
    }
    vector<string> generateParenthesis(int n) {
        string s = "(";
        recur(s,n,1,0);
        return ans;
    }
};