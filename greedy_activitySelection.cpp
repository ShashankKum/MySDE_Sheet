//N Meetings in a room, in this we sort based on departure time and when the departure time matches we sort on basis of arrival time in descending order.
//Time complexity will O(NlogN)
//Space used will be O(2N).


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(const pair<int,int> &a,const pair<int,int> &b){
        return (a.second==b.second)?(a.first>b.first):(a.second<b.second);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        if(n==1)  return 1;
        vector<pair<int,int>> job(n);
        int cnt=1;
        for(int i=0;i<n;i++){
            job[i].first = start[i];
            job[i].second = end[i];
        }
        sort(job.begin(),job.end(),comp);
        int dept = job[0].second;
        for(int i=1;i<n;i++){
            if(job[i].first>dept){
                cnt++;
                dept = job[i].second;
            }
        }
        return cnt;
    }
};


//Activity selection problem....to get the maximum number of non intersecting intervals
//Same approach for N meeting room also
//in this we sort the vector of structure based on deaprture time and start checking all the non intersecting intervals based on first...
  as all intervals are sorted based on departure if suppose interval 3 do not intersects with interval 2...it will surely not intersect with interval
  1 as departure of interval 1 must be before that of two since sorted on basis of departure.
//we used structure here we could have also used vector of vector.
//It takes O(NlogN) time and O(N) extra space.

struct combo{
    int pos;
    int start;
    int end;
};
bool sortsec(combo &a,combo &b){ //no nested function allowed in c++
        if(a.end==b.end)           //sorting condition returned such that there is ascending sort based on end and if end becomes equal it is sorted 
		{                            based on position.
        return(a.pos<b.pos);
		}
        else
        return(a.end<b.end);
    }
    
void maxMeetings(int start[], int end[], int n) {
    vector <combo> v(n);
    for(int i=0;i<n;i++)
    {
        v[i].start=start[i];
        v[i].end=end[i];
        v[i].pos=i+1;
    }
    sort(v.begin(),v.end(),sortsec);

    int i=0;
    cout<<v[0].pos<<" ";
    for(int j=1;j<n;j++)
    {
        if(v[j].start>v[i].end)
        {
            cout<<v[j].pos<<" ";
            i=j;
        }
    }
}