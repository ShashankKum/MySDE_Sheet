//In this as each row is sorted we can do a binary search in each row,and we also know that first integer of each row is greater than the last integer of the previous row, so we check the feasible row first and than do a binary search.
//It will take O(logN) time.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][n-1]>=target){ //find a row in which it can lie
                if(matrix[i][n-1]==target) //if it is the answer return it
                    return true;
                else{
                    if(binary_search(matrix[i].begin(),matrix[i].end(),target)) //do a binary search in that row
                        return true;
                    return false;
                }
            }
        }
        return false;
    }
};