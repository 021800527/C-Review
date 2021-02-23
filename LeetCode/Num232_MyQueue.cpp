#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> res;
    stack<int> transition;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        res.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!res.empty()){
            transition.push(res.top());
            res.pop();
        }
        int x = transition.top();
        transition.pop();
        while (!transition.empty()){
            res.push(transition.top());
            transition.pop();
        }
        return x;
    }

    /** Get the front element. */
    int peek() {
        while (!res.empty()){
            transition.push(res.top());
            res.pop();
        }
        int x = transition.top();
        while (!transition.empty()){
            res.push(transition.top());
            transition.pop();
        }
        return res.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return res.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */