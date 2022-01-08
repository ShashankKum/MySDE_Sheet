//minimum platforms needed so that there is no intersection of any train 
//required platform number will continuously change and once it increases than ans ...(ans=number)...to get maximum intersections at a time
//l is pointer for arrival and m for departure array
//this approach takes O(NlogN) time and no extra space.

//*further optimised approach is to use multimap(same as map but it do not have the constraint of unique key)...multimap <int,char> mp..
   insert both 'arr' and 'dep' array in it with 'a' representing arrival and 'd' for departure if 'a' comes increment number by one and    when 'd' comes decrement it by one....it will take O(N) time and O(N) extra space.* 

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    int ans=0,number=0;
    int l=0,m=0;
    while(l<n && m<n)
    {
        if(arr[l]<=dep[m]) //equal to is used beacause if arrival and departure timmings of two trains matches than also they can't arrive at same station 
        {                  //so platforms needed will increase. 
            l++;
            number++;
            ans=max(ans,number);
        }
        else
        {
            number--;
            m++;
        }
    }
    return ans;
}