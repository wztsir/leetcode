#include <iostream>  
#include <vector>  
  
using namespace std;  
  
int partition(vector<int>& nums, int left, int right) {  
    int pivot = nums[left];  
    int i = left + 1, j = right;  
    while (i <= j) {  
        if (nums[i] < pivot) {  
            i++;  
        } else if (nums[j] >= pivot) {  
            j--;  
        } else {  
            swap(nums[i++], nums[j--]);  
        }  
    }  
    swap(nums[left], nums[j]);  
    return j;  
}  
  
void quickSort(vector<int>& nums, int left, int right) {  
    if (left < right) {  
        int pivotIndex = partition(nums, left, right);  
        quickSort(nums, left, pivotIndex - 1);  
        quickSort(nums, pivotIndex + 1, right);  
    }  
}  
  
int main() {  
    vector<int> nums = {5, 1, 9, 3, 7, 6, 8, 2, 4};  
    quickSort(nums, 0, nums.size() - 1);  
    for (int num : nums) {  
        cout << num << " ";  
    }  
    cout << endl;  
    return 0;  
}