#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int i, j;
        int flag;
        for (i = 1; i <nums.size(); i++) {
            flag = nums[i];
            for (j = i - 1;j>=0 && flag < nums[j]; j--) {
                nums[j + 1] = nums[j];
            }
            nums[j+1] = flag;
        }
        return nums;
    }
};