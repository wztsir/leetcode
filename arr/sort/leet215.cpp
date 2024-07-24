#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
using namespace std;
int selectSort(vector<int>& nums, int left, int right, int index){
    //默认key的位置是left
    int i = left, j = right, key = nums[left];
    while(i < j){
        while(i < j && nums[j] > key)j--;
        while(i < j && nums[i] <= key)i++;
        if(i < j)swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    if(index > i) return selectSort(nums, i+1, right, index);
    else if(index < i)return selectSort(nums, 0, i-1, index);
    else return nums[i];
}
int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return selectSort(nums, 0, n-1, n-k);
}
int main()
{
    vector<int> arr = {3,2,3,1,2,4,5,5,6};
    findKthLargest(arr, 4);
   system("pause");
   return 0;
}
