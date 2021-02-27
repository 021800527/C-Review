#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int sum = 0;
        vector<int> transition;
        vector<vector<int>> res;
        for (int i = 1; i < target; ++i) {
            sum = sum + i;
            transition.push_back(i);
            if (sum == target){
                res.push_back(transition);
            }
            while (sum > target){
                sum = sum - transition.front();
                transition.erase(transition.begin());
            }
        }
        return res;
    }
};