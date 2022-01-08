//Maximum Product Subarray, for array containing positive negative and zero values.
//The simplest way is to use two loops using O(n^2) time and O(1) time, in which we continuously store the maximum value encountered in a variable.
//One better solution is to get the result in O(N) time and O(2*N) space.
//Note: In this we use the logic that whenever 0 is encountered continuing to multiply will always give us zero. So whenever 0 comes we can make the product till that point as
        1 as if we encountered a new array and start looking for maximum value again. we use 2 array one for forward multiplication and one for backward.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int a[n],b[n];
        int ma=nums[0],k=nums[n-1];
        (nums[0]==0)?a[0]=1:a[0]=nums[0];               //a[0] set to 1 if initital element is 0 or else set to the same value as that of value at index.
        (nums[n-1]==0)?b[n-1]=1:b[n-1]=nums[n-1];       //same logic as above
        for(int i=1;i<n;i++){
            a[i]=a[i-1]*nums[i];
            ma=max(ma,a[i]);
            if(nums[i]==0) a[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            b[i]=b[i+1]*nums[i];
            k=max(k,b[i]);
            if(nums[i]==0) b[i]=1;
        }
        ma=max(ma,k);
        return ma;
    }
};

//The most optimal way is to get the result in O(N) time and O(1) space.
//In this the maxval will store the max value till that index and minval will have the minimum value till that index.
//The logic is that minval will have minimum of running product and current value, so will always have running product having only one -ve element and when other negative element
//will come we will swap minval and maxval so that set of two negatives are formed in maxval which will be max value till than,this will make sure that at any time maxval is max.
//we also use the logic that if a>b than -a<-b -> the sole reason for swapping.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int minval=1,maxval=1,ans=-11;
        for(int i=0;i<n;i++){
            if(nums[i]<0)             //whenever -ve value comes in nums swap maxval and minval as if a>b than -a<-b
                swap(maxval,minval);
            maxval=max(maxval*nums[i],nums[i]);  //maxval will get the maximum of running product and the current value
            minval=min(minval*nums[i],nums[i]);  //minval will get the minimum of running product and current value
            ans=max(ans,maxval);                 //stores the maximum value at each step
        } 
        return ans;  //return the maximum product
    }
};

