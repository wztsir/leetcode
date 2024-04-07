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
int clear(vector<vector<int>>& points, int m1, int m2){
    int temp, a1, a2, r1 = 0, r2 = 0,n = points.size();
    r1 = abs(points[m2][0] - points[m1][0]) + abs(points[m2][1] - points[m1][1]);
    for(int i = 0; i < n; i++){
        a1 = abs(points[i][0] - points[m1][0]) + abs(points[i][1] - points[m1][1]);
        a2 = abs(points[i][0] - points[m2][0]) + abs(points[i][1] - points[m2][1]);
        temp = max(a1, a2);
        if(temp > r1){
            r1 = temp;
            r2= r1;
        }else if(temp > r2){
            r2 = temp;
        }
    }
    return r2;
}
int clear2(vector<vector<int>>& points, int m1, int m2, int ban){
    int temp, a1, a2, r1 = 0, r2 = 0,n = points.size();
    r1 = abs(points[m2][0] - points[m1][0]) + abs(points[m2][1] - points[m1][1]);
    for(int i = 0; i < n; i++){
        if(i == ban)continue;
        a1 = abs(points[i][0] - points[m1][0]) + abs(points[i][1] - points[m1][1]);
        a2 = abs(points[i][0] - points[m2][0]) + abs(points[i][1] - points[m2][1]);
        temp = max(a1, a2);
        if(temp > r1){
            r1 = temp;
        }
    }
    
    return r1;
}
int minimumDistance(vector<vector<int>>& points) {
    int n = points.size();
    vector<int> x(n);
    vector<int> y(n);
    iota(x.begin(), x.end(), 0);
    iota(y.begin(), y.end(), 0);
    sort(x.begin(), x.end(), [&](int i, int j) {
        return points[i][0] < points[j][0];
    });
    sort(y.begin(), y.end(), [&](int i, int j) {
        return points[i][1] < points[j][1];
    });
    int m1, m2;
    int res = INT_MAX;
    m1 = x[n-1],m2 = x[0];
    res = min(clear(points, m1, m2), res);
    m1 = x[n-2],m2 = x[0];
    res = min(clear2(points, m1, m2, x[n-1]), res);
    m1 = x[n-1],m2 = x[1];
     res = min(clear2(points, m1, m2, x[0]), res);

    m1 = y[n-1],m2 = y[0];
     res = min(clear(points, m1, m2), res);
    m1 = y[n-2],m2 = y[0];
     res = min(clear2(points, m1, m2, y[n-1]), res);
    m1 = y[n-1],m2 = y[1];
     res = min(clear2(points, m1, m2, y[0]), res);

    return res;
    

} 

int main()
{
   vector<vector<int>> p = {{3,10},{5,15},{10,2},{4,4}};
   minimumDistance(p);
   return 0;
}
