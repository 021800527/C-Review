#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int>sortArray(vector<int> &nums){
        sort(nums.begin(),nums.end());
        return nums;
    }
    vector<int> PartitionSortArray(vector<int> &nums){
        int high = nums.size()-1;
        int low = 0;
        QuickSort(nums,low,high);
    }
    void QuickSort(vector<int> &num,int low, int high){
        if (low<high){
            int pivotpos = Partition(num,low,high);
            QuickSort(num,low,pivotpos-1);
            QuickSort(num,pivotpos+1,high);
        }
    }
    int Partition(vector<int>&nums,int low,int high){
        int flag = nums[low];
        while (low<high){
            while (low<high && nums[high]>flag) high--;
            nums[low] = nums[high];
            while (low<high && nums[low]<flag) low++;
            nums[high] = nums[low];
        }
        nums[low] = flag;
        return low;
    }
    vector<int> BubbleSortArray(vector<int> &nums){
        int i ,j;
        bool flag = false;
        for (i = 0;  i<nums.size() ; i++) {
            for (j = nums.size()-1 ; j>i ; j--) {
                if (nums[j-1]>nums[j]){
                    swap(nums[j-1],nums[j]);
                    flag = true;
                }
            }
            if (flag== false)
                break;
        }
        return nums;
    }

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