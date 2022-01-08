//We have to partition it in two equal halves so if we can place the exact half in one array than the other half will automatically be part of next array.
//so first the sum must be even so that it can be divided in two equal halves, now we have the array and we have to find elements same as a given sum.
//So it is now reduced to 0-1 Knapsack form.
//NOTE: WE USE THE EXACT SAME TECHNIQUE TO SOLVE SUBSET SUM ALSO, IN WHICH WE HAVE TO CHECK IF THERE IS A SUBSET WHICH HAS SUM = GIVEN VALUE.

class Solution {
public:
    int arr[201][10007];
    bool part(vector<int>& nums,int i,int sum){
        //Base condition
        if(i<0 && sum!=0)
        return false;
        if(sum==0)
        return true;
        //Use previous stored value DP
        if(arr[i][sum]!=-1)
            return arr[i][sum];
        //Recur
        if(nums[i]<=sum)  //in this case the current value can be taken or can not be taken
        return arr[i][sum]=part(nums,i-1,sum-nums[i])||part(nums,i-1,sum); 
        else  //in this case we cant take as it is even greater than 1
        return arr[i][sum]=part(nums,i-1,sum);
    }
    bool canPartition(vector<int>& nums) {
        int s1=0,s2=0,n=nums.size();
        int sum=0;
        memset(arr,-1,sizeof(arr));
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2!=0) return false; //it cant be partitioned in two halves
        else{
        sum/=2;
        return part(nums,n-1,sum);
        }
    }
};

//It is a version of 0-1 Knapsack only.
//This recursive code for palindrome partitioning will also work,as in this we are taking all possibilities how elements can be filled in both the arrays.

class Solution {
public:
    int arr[201][20001];
    bool part(vector<int>& nums,int i,int s1,int s2){
        cout<<s1<<" "<<s2<<endl;
        if(i<0 && s1!=s2)
        return false;
        if(i<0 && s1==s2)
        return true;
        return part(nums,i-1,s1+nums[i],s2)||part(nums,i-1,s1,s2+nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        int s1=0,s2=0,n=nums.size();
        memset(arr,-1,sizeof(arr));
        return part(nums,n-1,0,0);
    }
};