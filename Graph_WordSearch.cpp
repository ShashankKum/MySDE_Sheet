//In this we need to look if the string is found in grid, the characters can be either vertiaclly or horizontally adjacent.
//We use the concept of backtrackinfg to do it.
//Once there is a mismatch the search ends.


class Solution {
public:
    bool look(vector<vector<char>> &board, string word,int i,int j,int l){
        if(l==word.size())  return true;   //if entire string is found return true. base case
        //if it exceeds boundry or do not matches with running string return false
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[l])  return false;  
        board[i][j]='0';                                  //mark the position as visited
        //once we get true just recursively return it back
        if(look(board,word,i-1,j,l+1)) return true;       //up
        if(look(board,word,i,j-1,l+1)) return true;       //left
        if(look(board,word,i,j+1,l+1)) return true;       //right
        if(look(board,word,i+1,j,l+1)) return true;       //down
//It will not reach here only when function call returns true, but in that case we have the answer so no issue if value is reset or not
        board[i][j]=word[l];                              //unmark it once its neighbouring loops are done
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){                             //we need to check string starting from each position
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && look(board,word,i,j,0))   //only move forward if first char matches
                    return true;
            }
        }
        return false;
    }
};