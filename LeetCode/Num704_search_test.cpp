#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        return search_test(nums,target,low,high);
    }
    int search_test(vector<int>& nums,int target,int low,int high){
        if (low>high)
            return -1;
        int mid;
        mid = (low+high)/2;
        if (target>nums[mid])
            search_test(nums,target,mid+1,high);
        else if (target<nums[mid])
            search_test(nums,target,low,mid-1);
        else
            return mid;
    }
};