#include <iostream>
#include <stack>
using namespace std;
class SortedStack {
private:
    stack<int>s1;//原栈为升序
    stack<int>s2;//辅助栈为降序
public:
    SortedStack() {

    }

    void push(int val) {
        while(!s2.empty()&&s2.top()>val){//辅助栈中存在比val大的值
            s1.push(s2.top());
            s2.pop();
        }
        while(!s1.empty()&&s1.top()<val){//原栈中有比val小的值
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
    }

    void pop() {
        while(!s2.empty()){//清空辅助栈
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) s1.pop();
    }

    int peek() {
        while(!s2.empty()){//清空辅助栈
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) return s1.top();
        else return -1;
    }

    bool isEmpty() {
        return s1.empty()&&s2.empty();
    }
};
int main(){
    SortedStack test;
    test.push(1);
    test.push(2);
    test.peek();
    test.pop();
    test.peek();
    return 0;
}
/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */