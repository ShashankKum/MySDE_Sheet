//Valid paranthesis matching consisting of '(','*',')' where '*' can be left or right paranthesis or an empty string.
//we make use of two stacks for '*'&'('... whenever a closing brace comes we first look for '(' to pop and if it is not available we than pop '*'.
//the '*' being popped will not harm any balancing for '(' as if till that position '(' do not exists than only '*' is being popped, and '(' can 
//never be balanced by any previous '*'...as )( is not balanced.
//We will than look for top '*'and top '(' for matching.


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1;  //stack for '('
        stack<int> s2;  //stack for '*'
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')  s1.push(i); //push indices to check while balancing '*' & '('
                else{
                    if(s[i]==')'){
                        if(s1.empty()){
                            if(s2.empty()) return false;
                            else{
                                s2.pop();
                            }
                        }
                        else s1.pop();
                    }
                    else s2.push(i);
                }
        }
//Only that '*' which comes after '(' can be used for balancing it so we used indices and the top of the * stack will contain the last indice for * and same for (.
        while(!s1.empty() && !s2.empty()){
                    if(s1.top()<s2.top()){
                        s1.pop();
                        s2.pop();
                    } 
                    else
                    return false;
                }
        if(!s1.empty() && s2.empty()) return false; //no '*' available so there is no chance
        return true;
    }
};