//the first and last elements of each row is 1 and other are the sum of v[i-1][j-1]+v[i-1][j],and each time number of columns increase by 1
//Time complexity is O(N^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        int n=0,i=0;
        for(int i=0;i<numRows;i++){
            v[i].resize(i+1);
            n++;
        for(int j=0;j<n;j++){
            if(j==0 || j==n-1)
                v[i][j]=1;
            else
                v[i][j]=v[i-1][j-1]+v[i-1][j];
        }
        }
        return v;
    }
};

//To get value at nth row and mth column of pascals triangle the formula is nCr assuming n and m starts from 0.

//combination will take O(N) time so to get it for entire row will take O(N^2) time so we find a logic that by moving i in a row from 0 to k we always need to multiply
  by (n-i) and devide by (i+1) to get value at every next column of a row.

for(int i=0;i<k;i++){ //this will take O(N) time to get result for the whole row.
	res*=(n-i);
	res/=(i+1);
}

//code for combination function
ll combination(int n,int r){
    ll res,res1=1,res2=1;
    for(int i=n;i>(n-r);i--)
    res1*=i;
    for(int i=r;i>1;i--)
    res2*=i;
    res=res1/res2;
    return res;
}