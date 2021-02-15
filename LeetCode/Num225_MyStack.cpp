#include <iostream>
#include <queue>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> res;
    queue<int> transition;
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        while (!res.empty()){

        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = res.back();
        res.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return res.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return res.empty();
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