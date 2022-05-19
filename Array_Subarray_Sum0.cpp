 //get a subarray with sum=0 in O(N) time and O(N) space
//Three Conditions required -> sum==0, arr[i]==0, sum value repeats


bool subArrayExists(int arr[], int n)
    {
        int sum=0;
        set<int> s;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0 || arr[i]==0 || s.find(sum)!=s.end())
                return true;
            else s.insert(sum);
        }
        return false;
     }