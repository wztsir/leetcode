#include<vector>
#include<algorithm>
using namespace std;
//这种区间题目
//其实可以直接枚举，
//枚举以0排还是以1排，从大到小
//再枚举相等时是从大到小吗，还是从小到大
bool static cmp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    if(points.size()==0)return 0;
    int res = 1, r = points[0][1];
    for(auto& it : points){
        if(it[0] <= r)continue;
        else{
            res++;
            r = it[1];
        }
    }
    return res;
}