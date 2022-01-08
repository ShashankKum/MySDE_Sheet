//Fractional Knapsack problem in which you can also use a part of the weight,the one in which you need to use the complete is done using dynamic.
//create an array of structure having (value,weight,ratio) and sort it on basis of ratio(v/w).
//it uses O(N) extra space and O(NlogN) time complexity.

/*
struct Item{
    int value;
    int weight;
}
*/

struct my{
  int val;
  int w;
  double ratio;
};
bool comp(my a,my b)  //sorting it in descending value/weight
{
    return (a.ratio>b.ratio);
}
// function to return total profit

double fractionalKnapsack(int W, Item arr[], int n)
{
    my ar[n];
    double tot=W,sum=0;
    for(int i=0;i<n;i++)
    {
       ar[i].val=arr[i].value;
       ar[i].w=arr[i].weight;
       ar[i].ratio=arr[i].value/(double)arr[i].weight; //typecasting
    }
    sort(ar,ar+n,comp);
    for(int i=0;i<n;i++)
    {
        if(tot>=ar[i].w)  //getting sum and remaining weight to be filled
        {
        sum+=ar[i].val;
        tot-=ar[i].w;
        }
        else
            {
              sum += ar[i].ratio*(tot);
              break;
            }
    }
    return sum;
}