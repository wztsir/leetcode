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
void swap(vector<int>& nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
//分区函数，实际的本质是将某个元素放到对应的位置，所以快速排序也可以叫做点排序（个人理解）
int partition(vector<int>& nums, int left, int right){
    int pivot = nums[left];
    int i = left+1, j = right;
    while(i < j){
        while(i < j && nums[i] <= pivot)i++;
        while(i < j && nums[j] > pivot)j--;
        if(i < j)swap(nums, i, j);
    }
    swap(nums, left, i);
    return i;
}
void quicksort(vector<int>& nums, int left, int right){
    if(left >= right)return;
    int p = partition(nums, left, right);
    quicksort(nums, left, p-1);
    quicksort(nums, p+1, right);
}

//冒泡排序
void maopao(vector<int> nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n - i; j++){
           if(nums[j] > nums[j+1]){ 
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
           }
        }
    }
}
int main()
{
   system("pause");
   return 0;
}
