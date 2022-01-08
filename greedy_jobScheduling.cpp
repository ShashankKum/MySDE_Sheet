//this is greedy approach for job scheduling problem where we have each job with its deadline and each will take one unit time
//we sort the structured array based on profit in descending order and allocate each job to its last slot available so that the previous slots 
  are still vacant.
//takes N^2 time and N extra space complexity(for boolean array).

struct Job{
   int ind;
   int dead;
   int profit;
};

bool comp(Job a,Job b)
{
    return (a.profit>b.profit); 
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
   sort(arr,arr+n,comp);  //NlogN time
   bool b[101];           //N extra space
   pair<int,int> pi={0,0};
   int k;
   memset(b,false,sizeof(b));
   for(int i=0;i<n;i++)    //N^2 time
   {
    k=arr[i].dead;
    while(k>0)
    {
       if(b[k]==false)
       {
           pi.second+=arr[i].profit;
           pi.first++;
           b[k]=true;
           break;
       }
       else
       k--;
    }
   }
   return pi;
} 
