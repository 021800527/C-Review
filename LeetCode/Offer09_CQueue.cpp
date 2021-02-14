#include <iostream>
#include <stack>
using namespace std;
class CQueue {
public:
    stack<int>res;
    stack<int>transition;
    CQueue() {

    }

    void appendTail(int value) {
        res.push(value);
    }

    int deleteHead() {
        while (!res.empty()){
            transition.push(res.top());
            res.pop();
        }
        if (transition.empty())
            return -1;
        else
            transition.pop();
        while (!transition.empty()){
            res.push(transition.top());
            transition.pop();
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */