#include<vector>
using namespace std;
int findLeft(vector<int>& nums, int target){
    int left = 0, right = nums.size();
    while(left < right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            right = mid;
        }else if(nums[mid] > target){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    if(left < 0 || left >= nums.size())return -1;
    return nums[left] == target ? left : -1;
}
int findRight(vector<int>& nums, int target){
    int left = 0, right = nums.size();
    while(left < right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    if(left - 1 < 0 || left - 1 >= nums.size())return -1;
    return nums[left-1] == target ? left-1 : -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0)return {-1, -1};
    int l = findLeft(nums, target);
    int r = findRight(nums, target);
    return {l, r};
}