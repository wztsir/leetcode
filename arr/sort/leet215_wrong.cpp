// class Quick {

//     public static void sort(int[] nums) {
//         // 为了避免出现耗时的极端情况，先随机打乱
//         shuffle(nums);
//         // 排序整个数组（原地修改）
//         sort(nums, 0, nums.length - 1);
//     }

//     private static void sort(int[] nums, int lo, int hi) {
//         if (lo >= hi) {
//             return;
//         }
//         // 对 nums[lo..hi] 进行切分
//         // 使得 nums[lo..p-1] <= nums[p] < nums[p+1..hi]
//         int p = partition(nums, lo, hi);

//         sort(nums, lo, p - 1);
//         sort(nums, p + 1, hi);
//     }

//     // 对 nums[lo..hi] 进行切分
//     private static int partition(int[] nums, int lo, int hi) {
//         int pivot = nums[lo];
//         // 关于区间的边界控制需格外小心，稍有不慎就会出错
//         // 我这里把 i, j 定义为开区间，同时定义：
//         // [lo, i) <= pivot；(j, hi] > pivot
//         // 之后都要正确维护这个边界区间的定义
//         int i = lo + 1, j = hi;
//         // 当 i > j 时结束循环，以保证区间 [lo, hi] 都被覆盖
//         while (i <= j) {
//             while (i < hi && nums[i] <= pivot) {
//                 i++;
//                 // 此 while 结束时恰好 nums[i] > pivot
//             }
//             while (j > lo && nums[j] > pivot) {
//                 j--;
//                 // 此 while 结束时恰好 nums[j] <= pivot
//             }
//             // 此时 [lo, i) <= pivot && (j, hi] > pivot

//             if (i >= j) {
//                 break;
//             }
//             swap(nums, i, j);
//         }
//         // 将 pivot 放到合适的位置，即 pivot 左边元素较小，右边元素较大
//         swap(nums, lo, j);
//         return j;
//     }

//     // 洗牌算法，将输入的数组随机打乱
//     private static void shuffle(int[] nums) {
//         Random rand = new Random();
//         int n = nums.length;
//         for (int i = 0 ; i < n; i++) {
//             // 生成 [i, n - 1] 的随机数
//             int r = i + rand.nextInt(n - i);
//             swap(nums, i, r);
//         }
//     }

//     // 原地交换数组中的两个元素
//     private static void swap(int[] nums, int i, int j) {
//         int temp = nums[i];
//         nums[i] = nums[j];
//         nums[j] = temp;
//     }
// }
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
void swap(vector<int> & nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int partition(vector<int>& nums, int left, int right){
    int key= nums[left];
    int i = left, j = right;//这里的i的值不需要+1，因为万一key的位置不需要改变
    while(i < j){
        //左右移动法：细节是 
        //基准值 key 在左边， right 小兵先走；基准值 key 在右边，left 小兵先走。
        //如果key在左边，left先走，最后两个哨兵碰面的时候该值大于key，则最后交换的时候错误
        // while(i < j && nums[i] <= privot)i++;
        // while(i < j && nums[j] > privot)j--;
        while(i < j && nums[j] > key)j--;
        while(i < j && nums[i] <= key)i++;
        if(i < j)swap(nums, i, j);
    }
    swap(nums, left, i);
    return i;
}
int selectSort(vector<int>& nums, int index, int p){
    int next_p;
    if(index == p)return nums[p];
    else if(index > p){
        next_p = partition(nums, p+1, nums.size()-1);
    }else next_p = partition(nums, 0, p-1);
    return selectSort(nums, index, next_p);
}
void shuffle(vector<int>& nums) {
    int n = nums.size();
    srand(time(NULL));
    for (int i = 0 ; i < n; i++) {
        // 生成 [i, n - 1] 的随机数
        int r = i + rand()%(n-i);;
        swap(nums, i, r);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    shuffle(nums);
    int p = partition(nums, 0, nums.size()-1);
    int index = nums.size() - k;
    return selectSort(nums, index, p);
}
int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    findKthLargest(nums, 4);
    system("pause");
    return 0;
}
