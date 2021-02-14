#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int k = 0;
        for(auto n : pushed)
        {
            s.push(n);
            while(!s.empty() && s.top() == popped[k])
            {
                s.pop();
                ++k;
            }
        }
        return s.empty();
    }
};