//Implement Queue using stack.
//For this we perform all the basic functions of queue that is push(at back) pop(from front) peek(front element) and check wether empty.
//For this we use inbuilt stack(declared globally) for functions to access it.
//Since in stack(LIFO) we pop the latest entered element but in queue(FIFO) we pop the last entered element,so we use the technique to reverse 
//the order of elements in stack using two different stacks to do it.

class MyQueue {
    stack<int> *s1;  //we declare stack globally so that it is accessible by all functions 
    stack<int> *s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        s1=new stack<int>;
        s2=new stack<int>;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {  
        while(!s1->empty()){
            s2->push(s1->top());
            s1->pop();
        }
        s1->push(x);
        while(!s2->empty()){
            s1->push(s2->top());
            s2->pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {  //sinsce we are using inbuilt stack class so top pointer is adjusted itself
        int a;
        a=s1->top();
        s1->pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        return s1->top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1->empty();
    }
};