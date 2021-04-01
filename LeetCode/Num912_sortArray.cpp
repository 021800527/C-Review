#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> ShellSortArray(vector<int> &nums){
    int i;
    int j ;
    int flag;
    int n = nums.size();
        for (int dk = n/2; dk >=1; dk=dk/2) {
            for (i = dk;  i<=n ; i++) {
                if (nums[i]<nums[i-dk]){
                    flag = nums[i];
                    for (j = i-dk;  j>=0 && flag <nums[j] ; j=j-dk) {
                        nums[j+dk] = nums[j];
                    }
                    nums[j+dk] = nums[j];
                }
            }
        }
        return nums;
    }

    vector<int> BinInsertSortArray(vector<int>& nums) {
        int i,j;
        int low,high,mid;
        int flag;
        for (i = 1; i <nums.size() ; i++) {
            flag = nums[i];
            low = 0;
            high = i -1;
            while (low<=high){
                mid = (low+high)/2;
                if (nums[mid]>flag)
                    high = mid-1;
                else
                    low = mid + 1;
            }
            for (j = i-1;  j>=high+1 ; j--) {
                nums[j+1] = nums[j];
            }
            nums[high+1] = flag;
        }
    }

    vector<int> InsertSortArray(vector<int>& nums) {
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