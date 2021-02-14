#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>res;
    stack<int>transition;
    MinStack() {

    }

    void push(int x) {
        res.push(x);
        if (transition.empty()||x<=transition.top())
            transition.push(x);
    }

    void pop() {
        if (res.top() == transition.top())
            transition.pop();
        res.pop();
    }

    int top() {
        return res.top();
    }

    int min() {
        return transition.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */