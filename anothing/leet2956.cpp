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

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> n1, n2;
    int a1 = 0, a2 = 0;
    for(auto n : nums1){
        n1.insert(n);
    }
    for(auto n : nums2){
        n2.insert(n);
        if(n1.find(n) != n1.end())a2++;
    }
    for(auto n : nums1){
        if(n2.find(n) != n2.end())a1++;
    }
    return {a1, a2};
    
}
int main()
{
   system("pause");
   return 0;
}

