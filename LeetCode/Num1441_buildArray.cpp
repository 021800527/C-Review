#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int size = target.size();
        vector<string>res;
        int flag =  1;
        for (int i = 0; i < size; ++i) {
            for (int j = flag; j <= n; ++j) {
                res.push_back("Push");
                if (j != target[i]){
                    res.push_back("Pop");
                }
                else
                {
                    flag = j + 1;
                    break;
                }
            }
        }
        return res;
    }
};