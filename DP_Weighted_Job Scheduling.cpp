//Simple recursive code, we will have two options wether can take a task or not, once a task is taken we have to check for next not colliding task,
  for this we keep all three in a structure and than sort them best on the end time.
//NOTE: We know we have to use dynamic programming if the program requires optimal answer and we have to make choices which one to select.

class Solution {
public:
    struct job{
        int st,end,value;
    };
    //static function can be called using class name and :: we do not need object to call it and it is initialized once.
    static bool comp(job a,job b){ 
        return (a.end < b.end);
    }
    int get_profit(job arr[],int i,int limit){
        if(i<0)
        return 0;
        if(arr[i].end<=limit)
        return max(arr[i].value+get_profit(arr,i-1,arr[i].st), get_profit(arr,i-1,limit));
        else
        return get_profit(arr,i-1,limit);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        job arr[n];
        for(int i=0;i<n;i++){
            arr[i].st=startTime[i];
            arr[i].end=endTime[i];
            arr[i].value=profit[i];
        }
        sort(arr,arr+n,comp);
        return get_profit(arr,n-1,1000000000);
    }
};

//We know we have to use dynamic programming if the program requires optimal answer and we have to make choices which one to select.
//we first store all three start,end,profit in a structure array and than sort them based on end time, we than recur from end,
//either we include the value or exclude it.
//If we include the value we move to the previous structure which has end time less than equal to start time of cuurent structure.
//Here we cant use else part as a seperate a[i] may be created for the else part which will result in conflict.

class Solution {
public:
    int a[50005];
    struct job{
        int st,end,value;
    };
    //static function can be called using class name and :: we do not need object to call it and it is initialized once.
    static bool comp(job a,job b){ 
        return (a.end < b.end);
    }
    int get_profit(job arr[],int i){
        if(i<0)
        return 0;
        if(a[i]!=-1)
            return a[i];
        int j=i-1;
        while(j>=0 && arr[j].end>arr[i].st)  //search for the nearest possible position
        j--;
        
        return a[i]=max(arr[i].value+get_profit(arr,j), get_profit(arr,i-1));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        memset(a,-1,sizeof(a));
        job arr[n];
        for(int i=0;i<n;i++){
            arr[i].st=startTime[i];
            arr[i].end=endTime[i];
            arr[i].value=profit[i];
        }
        sort(arr,arr+n,comp);
        return get_profit(arr,n-1);
    }
};

//We can optimize it further from n^2 to nlogn by using binary search to search the previous position.

int binarySearch(Job jobs[], int index) 
{ 
    // Initialize 'lo' and 'hi' for Binary Search 
    int lo = 0, hi = index - 1; 
  
    // Perform binary Search iteratively 
    while (lo <= hi) 
    { 
        int mid = (lo + hi) / 2; 
        if (jobs[mid].finish <= jobs[index].start) 
        { 
            if (jobs[mid + 1].finish <= jobs[index].start) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    } 
  
    return -1; 
} 