//Sum of all subarrays in O(N) time,we can do it in O(N^2) time by producing all the subarrays.
//by looking at example we find a formula that sum+=arr[i]*(n-i)*k..where k[1,n].
//we also use modualr arithmetic to get the result in sum modulo (109+7).

class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
       long long int sum=0,k=1,z;
       long long int mod=1000000007;
       for(int i=0;i<n;i++){
           z=(n-i)*k;
           sum=(sum+((a[i]%mod)*(z%mod)%mod))%mod;
           k++;
       }
       return sum;
    }
};