//Create a stack to have all the given operations in O(1) time.
//took use of two vectors one keeping the nodes present and one having the current smallest value so whenever needed can be retrived in O(1) time.

class MinStack {
    int l=9999999;
    vector<int> v1;
    vector<int> v2;
    int k=0;
public:
    /** initialize your data structure here. */
    MinStack() {
        v1.assign(l,0);  //making its length l with all values 0.
        v2.assign(l,0);
    }
    
    void push(int x) {
        v1[k]=x;
        if(k>0)
        v2[k]=min(v2[k-1],x);
        else
        v2[k]=x;
        k++;
    }
    
    void pop() {
       k--; //we do not use erase() as in worst case erase take O(N) time.
    }
    
    int top() {  //get the top most position
        return v1[k-1];
    }
    
    int getMin() {  //get the current min value in stack
        return v2[k-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */