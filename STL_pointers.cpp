//STL
//Double ended queue is queue in which insertion and deletion takes place at both the ends,and has all functions similar as vector.
//In map,vector,deque(double ended queue..which is implemented using double linked list),set(has only unique elements) all these have similar functions..i.e

//erase in string and vector and deque ->  str.erase(str.begin() + 0, str.end() - 6)  // Deletes all characters between 0th index and str.end() - 6
//str.erase(str.begin() + 4)   // Deletes character at position 4
//in erase in cases of vector,set,string first element is the starting element we include it and second is the end but it is excluded in deleting.
//erase in map mp.erase(key) -> used to delete an element a specific key
//erase in set -> myset.erase(it1, it2),myset.erase(it1), it is same as that of string and vector but in this we cant use it+k,we have to move it to a particular position using it++ or
//it--, not just directly use it+k
//we can also directly delete a particular value(v[i]) in a set -> myset.erase(v[i])

//insert in vector -> v.insert(v.begin()+k,10)->to insert an element at a given index,in this 10 is inserted at kth index.
//insert in map and set -> mp.insert({n,val}),s.insert(val)  //as in this the position is not decided by us

//clear()->remove all the values.
//size()->to get the current length.
//find()->to check if a value exists or not....map->mp.find(x),set->s.find(x),vector->v.find(v.begin(),v.end(),x),deque->d.find(x)


//find in vector is somewhat different it returns the iterator to the first similar element to be found or else if not found returns v.end()(returning
//v.end() is same for other stls too).
    it = find (vec.begin(), vec.end(), ser); 
    if (it != vec.end()) 
    { 
        std::cout << "Element " << ser <<" found at position : " ; 
        std::cout << it - vec.begin() << " (counting from zero) \n" ;
    } 
//vector has pop_back() but not pop_front()
// Reversing elements from index 5 to index 7 
    reverse(vec1.begin() + 5, vec1.begin() + 8); 
// set size of 2D vector -> vector<vector<int>> vec( n , vector<int> (m, 0));
//to set the size of vector we use resize...v.resize(n+1)


//Use of auto to traverse in c++ instead of for loop or iterator,
// vector<int> adj[]; -> for(auto x:adj[a])    Can use any data type like int,bool,float etc.
// vector<int> v;     -> for(auto x:v)
// int arr[n]         -> for(auto x:arr)


//binary_search(start,end,val) is used in array and vector, it returns bool true or false, depending on element is found or not, array/vector needs to be sorted before using it.

//lower_bound(arr,arr+n,val) ->array,lower_bound(v.begin(),v.end(),val) ->vector -> it returns pointer/iterator to the first similar value found and if the value is not found 
  it returns a value just greater than val and if no value greter than val is found means it returns arr+n(in case of array) and v.end()(in case of vector).
//Same is for upper_bound, it just returns the next greater element even if the required value is present.

//searching(find) in map and set takes logn time as it is implemented using red black binary search tree but it can be optimized to O(1) time(in worst
//case O(N) time) using hashing ie. unordered_set,unordered_map.

//Deque stl has functions such as: push_front(),push_back(),pop_front(),pop_back()..(to insert and delete at both front and back.)

//Vector is nothing but a dynamic array... int* arr=new int[10].
//Dynamically allocated memory is allocated on Heap and non-static and local variables get memory allocated on Stack.
//Dynamically allocates memory for 10 integers continuously of type int and returns pointer to the first element of the sequence(arr).
  which is assigned to p(a pointer).
//There is a difference between declaring a normal array and allocating a block of memory using new. The most important difference is, normal arrays 
  are deallocated by compiler (If array is local, then deallocated when function returns or completes). 
  However, dynamically allocated arrays always remain there until either they are deallocated by programmer or program terminates.  
//When new is used to allocate memory for a C++ class object,the object's constructor is called after the memory is allocated. 
  Use the delete operator to deallocate the memory allocated with the new operator. 
//initializing value using new.
//int *p = new int(25);
//float *q = new float(75.25);