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
vector<int> numberGame(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> arr(n);
    for(int i=0; i < n; i+=2){
        arr[i] = nums[i+1];
        arr[i+1] = nums[i];
    }
    return arr;
}
int main()
{
   system("pause");
   return 0;
}
