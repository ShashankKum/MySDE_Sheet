//In this we have a cache(memory) of fixed size, so if size is not full and element is not already present just add it at end, if size is full remove least recently used and add the new   element at end, if the element to be added is already present than bring it to back as it becomes recently visited.
//map will have the key(page no.) and value pair and deque will have the key,whenever a key comes which already exists it is a cache hit,
  in this case we will erase the initial existing similar key from both deque and map and than add the key in deque and new key value pair in map.
  This is done because similar keys can have different values.  
//we will access the particular key in deque using
// LRU->In this we erase the least recently used if cache is filled to add a new key.
// Get()->in this the page is being visited,so bring the current visited element at back as it becomes recently visited.
// Put()->add a key at end always, if cache(deque) is filled delete the least recently visited to add new key,if same key is to be added(cache hit)
   delete the previous and add new. 

class LRUCache {
    deque<int> d;
    unordered_map<int,int> mp;
    int total;   //total declared globally
public:
    LRUCache(int capacity) {
        total=capacity; 
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())  //if value do not exists in cache return -1
            return -1;
        else {                     //if value exists bring the key to the back
            auto it=d.begin();
            while(*it!=key) it++;   //pointer to the node to be deleted
            d.erase(it); 
            d.push_back(key); //adding the recently visited item to the back,we cant use *it as it pointer reference is already erased
            return mp[key];
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()) //if key do not exists in cache
        {
            if(total==d.size()){ //remove from front and add the new key at end
                mp.erase(d.front());
                d.pop_front();
                d.push_back(key);
                mp.insert({key,value});
            }
            else{                //if space is there simply push the key at back of deque,and insert respective key value pair in map
               d.push_back(key);
               mp.insert({key,value}); 
            }
        }
        else{  //if key exists
            auto it=d.begin();
            while(*it!=key) it++; //get pointer to the key
            d.erase(it);          //deque and vector takes pointer in erase and map takes value(as value is unique).
            mp.erase(key);
            d.push_back(key);
            mp.insert({key,value}); 
        }
    }
};