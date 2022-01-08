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