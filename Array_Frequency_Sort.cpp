//We sort the elements of array such that the element with min frequency comes first and if frequecy of two elements is same than the bigger element comes first.

class Solution {
public:
    static bool compar(pair<int,int> a,pair<int,int> b){
        return ((a.first==b.first)?(a.second>b.second):(a.first<b.first));
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map <int,int> mp;
        for(int i=0;i<n;i++)  //we first map the values,using hash map as it takes O(1) insertion time in average case
            mp[nums[i]]++;
        
        vector <pair<int,int>> v; //we than puah the map values in avector pair
        auto it=mp.begin();
        while(it!=mp.end()){
            v.push_back({it->second,it->first});
            it++;
        }
        sort(v.begin(),v.end(),compar); //we sort the vector in ascending order of frequency,and if freq matches than bigger element first
        
        nums.clear(); //we clear the given nums array so that we do not use extra space for a new vector
        for(int i=0;i<v.size();i++){ //push the values base on frequency
            int k=v[i].first;
            while(k){
                nums.push_back(v[i].second);
                k--;
            }
        }
        return nums;
    }
};