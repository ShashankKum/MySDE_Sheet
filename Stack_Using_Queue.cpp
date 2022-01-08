//Same logic used as that used for implementing queue using stack.
//functions used for queue are front(),back(),empty(),pop(),top().

class MyStack {
    queue<int>* q1;
    queue<int>* q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        q1=new queue<int>;
        q2=new queue<int>;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!q1->empty()){
            q2->push(q1->front());
            q1->pop();
        }
        q1->push(x);
        while(!q2->empty()){
            q1->push(q2->front());
            q2->pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a;
        a=q1->front();
        q1->pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return q1->front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */